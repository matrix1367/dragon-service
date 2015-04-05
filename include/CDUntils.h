#ifndef CDUNTILS_H
#define CDUNTILS_H

#include <string>

namespace CDDragon
{


class CDUntils
{
public:
    CDUntils();
    virtual ~CDUntils();

    //static void PathRemoveFileSpec(std::string& path);
    static void PathRemoveFileSpec(std::string& f)
    {
        unsigned int i = f.find_last_of('\\');
        if (i != std::string::npos) f = f.substr(0,i+1); // f contains the result :)
    }

//    static bool fileExists(TCHAR* file)
//    {
//        WIN32_FIND_DATA FindFileData;
//        HANDLE handle = FindFirstFile(file, &FindFileData) ;
//        int found = handle != INVALID_HANDLE_VALUE;
//        if(found)
//        {
//           //FindClose(&handle); this will crash
//           FindClose(handle);
//        }
//        return found;
//    }
protected:
private:
};

}

#endif // CDUNTILS_H
