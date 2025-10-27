#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>

#include "library.h"

using namespace std;

class FileManager {
private:
    string booksFileName;
    string usersFileName;
    string activityLogFileName;

public:
    // Constructor
    FileManager(const string& booksFile = "data/books.txt", 
                const string& usersFile = "data/users.txt",
                const string& activityLogFile = "data/activity.log");
    
    // File operations
    bool saveLibraryData(Library& library);
    bool loadLibraryData(Library& library);
    
    // Individual file operations
    bool saveBooksToFile(Library& library);
    bool saveUsersToFile(Library& library);
    bool loadBooksFromFile(Library& library);
    bool loadUsersFromFile(Library& library);
    
    // Utility methods
    bool fileExists(const string& filename);
    void createBackup();
    void logActivity(const string& action,
                     const string& userId,
                     const string& userName,
                     const string& isbn);
};

#endif
