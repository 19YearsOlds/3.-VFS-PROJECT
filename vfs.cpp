#include <iostream>
#include <unordered_map>

using namespace std;


class VirtualFileSystem {
private:
    unordered_map<string, string> files;

public:

    void createFile(string filename, string content) {
        if (files.find(filename) != files.end()) {
            cout << "Error: File already exists.\n";
            return;
        }
        files[filename] = content;
        cout << "File '" << filename << "' created successfully.\n";
    }


    void readFile(string filename) {
        if (files.find(filename) == files.end()) {
            cout << "Error: File not found.\n";
            return;
        }
        cout << "File Content: " << files[filename] << endl;
    }


    void listFiles() {
        if (files.empty()) {
            cout << "No files in the system.\n";
            return;
        }
        cout << "Files in system:\n";
        for (const auto& file : files) {
            cout << "- " << file.first << endl;
        }
    }


    void deleteFile(string filename) {
        if (files.find(filename) == files.end()) {
            cout << "Error: File not found.\n";
            return;
        }
        files.erase(filename);
        cout << "File '" << filename << "' deleted successfully.\n";
    }
};

int main() {
    VirtualFileSystem vfs;
    int choice;
    string filename, content;

    while (true) {
        cout << "\nVirtual File System Menu:\n";
        cout << "1. Create File\n";
        cout << "2. Read File\n";
        cout << "3. List Files\n";
        cout << "4. Delete File\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter file name: ";
                getline(cin, filename);
                cout << "Enter file content: ";
                getline(cin, content);
                break;
            case 2:
                cout << "Enter file name to read: ";
                getline(cin, filename);
                vfs.readFile(filename);
                break;
            case 3:
                vfs.listFiles();
                break;
            case 4:
                cout << "Enter file name to delete: ";
                getline(cin, filename);
                vfs.deleteFile(filename);
                break;
            case 5:
                cout << "Exiting VFS...\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}