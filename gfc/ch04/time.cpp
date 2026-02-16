
overload GetTime;
void GetTime(long *ticks);
void GetTime(int* hours, int* minutes, int* seconds);

class Time {
    void GetTime(long* ticks);
    void GetTime(int* hours, int* minutes, int* seconds);
};

overload Error;
void Error(int errCode, char* errMsg = "");
void Error (char* errMsg);
