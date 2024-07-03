#include "Utilities.h"
#include "Command.h"



using namespace std;

int main(const int argc,const char* argv[]) {

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
			command3(argc, argv);
			break;
		}
	
	}
	else if (!strcmp(argv[1], "-c"))
	{
		int cmnd = readCCommand(argc, argv);
		switch (cmnd)
		{

			case 4:
				command4(argc, argv);	
				break;

			case 5:
				command5(argc, argv);
				break;
		}
	}
	else cout << "can't regconize command " << endl;


	return 0;
}