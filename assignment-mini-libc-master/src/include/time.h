struct timespec {
	int  tv_sec;
	long tv_nsec;
};
int nanosleep(const struct timespec *req, struct timespec * rem);
