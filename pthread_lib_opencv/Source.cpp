/* Include standard libraries */
#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>


/* Include OpenCV libraries */
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

/* Include libraries */
#include "threads.h"

/* Namespace used */
using namespace std;
using namespace cv;


/***************** User defined data types *****************/

/* Structure containing pointer to variables of frame */
typedef struct{
	Mat *frame;		/**<Pointer to frame */
	string *string;	/**<Pointer to window name */
	void *data;		/**<Pointer to data related to frame */
}frame_info_;

/**************************************************/


/******* Global Vraibales ********/

VideoCapture capture(0);		/**< Variable for camera */

Mutex_ l_Mutex;					/**< Reference of Mutex_ class */

pthread_mutex_t l_mutex_var;	/**< Mutex variable */

/********************************/


/***************** Static functions ***************/

/* Function to be passed for thread execution */
static void * threadFunction( void *arg );

/*********************************************/



int main( int argc, const char** argv )
{
/* Open camera */
capture.open(0);

/* Check camera device control */
if( !capture.isOpened() ){
	return -1;
}

/* Set frame properties */
capture.set(CV_CAP_PROP_FRAME_WIDTH, 640);
capture.set(CV_CAP_PROP_FRAME_HEIGHT, 480);

/* Local Variables for thread */
int8_t ret;
int8_t ret_1;
void * ptr;
void * ptr_1;

/********** Frame variables *************/

/* Data variables for frame 1 */
Mat frame;							/**<First frame */
string window_name = "Capture-1";	/**<First frame window name */
const char *frame_str = "FRAME-1";	/**<First frame data to be returned from thread */

/* Data variables for frame 2 */
Mat frame_2;						/**<Second frame */
string window_name_2 = "Capture-2";	/**<Second frame window name */
const char *frame_2_str = "FRAME-2";/**<Second frame data to be returned from thread */

/****************************************/

/**************** Structure variables for frames ****************/

frame_info_ frame_info_1 = { &frame, &window_name, (void *)frame_str };			/**<First frame structure info */

frame_info_ frame_info_2 = { &frame_2, &window_name_2, (void *)frame_2_str };	/**<Second frame structure info */

/***************************************************************/

	/* Initialize mutex */
	l_Mutex.initMutex( &l_mutex_var, NULL );

	/* Create object of Threads_ class */
	Threads_ * thread_1 = new Threads_( threadFunction, (void *)&frame_info_1 );
	Threads_ * thread_2 = new Threads_( threadFunction, (void *)&frame_info_2 );

	/* Print sizeof */
	cout << sizeof(frame_info_ *) << endl;
	cout << sizeof(Threads_ *) << endl;
	cout << sizeof(thread_1) << endl;
	cout << sizeof(thread_2) << endl;
	cout<< sizeof(l_Mutex) << endl;

	/* Create thread for frame 1 */
	ret = thread_1->create( NULL ); 
	if( ret ){
		printf("%s", "\nThread Creation Failed\n");
		perror("Error : ");
		return 1;
	}

	/* Create thread for frame 2 */
	ret_1 = thread_2->create( NULL ); 
	if( ret_1 ){
		printf("%s", "\nThread 2 Creation Failed\n");
		perror("Error : ");
		return 1;
	}

	/* Join thread */
	thread_1->join( &ptr);
	thread_2->join( &ptr_1);

	/* Print return values from thread */
	printf("\nReturn value from thread 1 is %s\n", (const char *)ptr);
	printf("\nReturn value from thread 2 is %s\n", (const char *)ptr_1);

	
/* Destroy Mutex to release system resources */
l_Mutex.destroyMutex(&l_mutex_var);

/* Release camera control */
capture.release();

cout << "\nPRESS ENTER TO FINISH" << endl;
/* HOLD */
getchar();

return 0;
}


/** \brief: Method to process a frame and display it
 * \param: Pointer to argument for
 * \return: Exit status of thread
 * 
 * This method accepts argument which is having
 * frame info i.e., frame address and window name for that frame.
 *
 * It simply capture the frame and display it.
*/
void * threadFunction( void *arg ){

	cout<< "\nThread Started.."<< endl;

	int c;	/**< Variable to get key input from user */

	/* Infinite Loop */
	for ( ; ; ){
		/* Lock mutex for camera control */
		if( (c = l_Mutex.lockMutex(&l_mutex_var)) != 0 ){
			printf("Error while locking mutex !!");
			perror("Error: ");
			break;
		}

		/* Capture frame */
		capture >> *((frame_info_*)arg)->frame;

		/* Unlock mutex for camera control */
		if( (c = l_Mutex.unlockMutex(&l_mutex_var)) != 0 ){
			printf("Error while Unlocking mutex !!");
			perror("Error: ");
			break;
		}

        /* Display frame in a window */
        if ( !(*((frame_info_*)arg)->frame).empty() ) {
			/* flip image */
			flip(*((frame_info_*)arg)->frame, *((frame_info_*)arg)->frame, 1);

			/* Show image */
			imshow( *((frame_info_*)arg)->string, *((frame_info_*)arg)->frame );
		}
        else{	printf("--(!) No captured frame -- Break!");  break;	}

		/* Wait for user input */
        c = waitKey(1);
		if( 'q' == (char)c ){ destroyWindow( *((frame_info_*)arg)->string ); break;	}

	}

	cout<< "\nThread Ended..!"<< endl;

	pthread_exit( ((frame_info_*)arg)->data );

return NULL;
}




/******************************************************************************************************/