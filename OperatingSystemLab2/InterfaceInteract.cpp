#include "InterfaceInteract.h"


InterfaceInteract::InterfaceInteract()
{

}

void InterfaceInteract::ReceiveCommand(Command c)
{
	emit SendCommand(c);
}