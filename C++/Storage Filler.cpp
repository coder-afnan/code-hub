#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
using namespace std;
namespace fs = std::filesystem;

int main()
{
	int files;
	cout << "Files to create: ";
	cin >> files;

	if (files <= 0)
	{
		cerr << "Please enter a positive number for the number of files.";
	}

	int numMB;
	cout << "Size for each file in MB: ";
	cin >> numMB;

	if (numMB <= 0)
	{
		cerr << "Invalid number. Please enter a valid positive number.";
		return 1;
	}

	// Define the file path to your need
	string filePath = "/storage/emulated/0/Code Bits/";
	string fileName = "Demo";
	string sourceFile = filePath + fileName + " 1";

	ofstream myFile(sourceFile);
	if (!myFile)
	{
		cerr << "Failed to create or open the file\n";
		return 1;
	}

	// Text to write in the file
	string largeText(1023, 'A');
	int textSize = largeText.size();
	unsigned long totalSize = static_cast<unsigned long>(numMB) * 1048576;
	unsigned long iterations = totalSize / textSize;
	// The file creation process
	// Creating the first file
	cout << "Starting file write...\n";
	for (unsigned long int i = 0; i < iterations; i++)
	{
		myFile << largeText;
	}
	// Taking account of the remaining size and filling it
	unsigned long int leftBytes = totalSize % textSize;
	if (leftBytes > 0)
	{
		for (unsigned long int i = 0; i < leftBytes; i++)
		{
			myFile << "A";
		}
	}

	myFile.close();
	cout << "File 1 created." << endl;

	//Creating copies of the source file
	for (int i = 2; i <= files; i++)
	{
		string copiedFile = filePath + fileName + " " + to_string(i);
		try
		{
			fs::copy_file(sourceFile, copiedFile);
			cout << "File " << i << " created." << endl;
		}
		catch (fs::filesystem_error &e)
		{
			cerr << "Error creating File " << i << ": " << e.what() << endl;
		}
	}
	cout << "All files created successfully!";

	return 0;
}