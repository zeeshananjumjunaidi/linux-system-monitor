#include <algorithm>
#include <iostream>
#include <math.h>
#include <thread>
#include <chrono>
#include <iterator>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cerrno>
#include <cstring>
#include <direct.h>
#include <time.h>
#include <util.h>
// #include <unistd.h>
#include <constant.h>
using namespace std;
class ProcessParser {
    public:
        static  Util util;
        static  Path path;

        static string getCmd(string pid){
           return path.basePath()+'/'+path.cmdPath();
        }
        static vector<string> getPidList(){
            vector<string> strings;

           return strings;
        }
        static string getVmSize(string pid){
            string line;
            string name ="VmData";
            string value;
            float result;
            ifstream stream = Util::getStream(Path::basePath()+pid+Path::statusPath());
            while(getline(stream,line)){
                if(line.compare(0,name.size(),name)==0){
                    istringstream buf(line);
                    istream_iterator<string> beg(buf), end;
                    vector<string> values(beg,end);
                    // conversion kb -> GB
                    result = (stof(values[1])/float(1024));
                    break;
                }
            };
            return to_string(result);
        
        }
        static string getCpuPercent(string pid);
        static long int getSysUpTime();
        static string getProcUpTime(string pid);
        static string getProcUser(string pid);
        static vector<string> getSysCpuPercent(string coreNumber = "");
        static float getSysRamPercent();
        static string getSysKernelVersion();
        static int getTotalThreads();
        static int getTotalNumberOfProcesses();
        static int getNumberOfRunningProcesses();
        static string getOsName();
        static string printCpuStats(vector<string> values1, vector<string>values2);
};