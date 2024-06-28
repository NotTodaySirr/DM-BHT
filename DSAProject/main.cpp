#include "Utilities.h"
#include "Command.h"



using namespace std;

int number(int n)
{
	cout << n;
	return n;
}

int main(int argc, char* argv[]) {

	if (argc < 2) {
		  cout << "Invalid arguments" << endl;
		  return 1;
	}
	
	if (!strcmp(argv[1], "-a"))
	{
		int cmnd = readACommand(argc, argv);
		switch (cmnd)
		{
		case 1 : 
			command1(argc, argv);
			break;

		case 2:
			command2(argc, argv);
			break;

		case 3:
			//command 3 goes here
			break;
		}
	
	}
	else if (!strcmp(argv[1], "-c"))
	{
		//code run here
		int cmnd = readCCommand(argc, argv);
		switch (cmnd)
		{

			case 4:
				//command 4 goes here
				break;

			case 5:
				//command 5 goes here
				break;
		}
	}

	else cout << "can't regconize command " << endl;
	

    return 0;
}