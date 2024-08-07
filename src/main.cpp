#include <egt/ui>
#include <egt/uiloader.h>

#include <iostream>

#include "uartFunc.h"
#include "bleDevice.h"

void btnProcess(NAVI_DIRECTIONS dir, int fdUart)
{
	char buff[128];
	std::cout << "BLE " << fdUart << std::endl;
	
	switch( dir )
	{
		case NAVIDIR_ARRIVED:
			std::cout << "Arrived" << std::endl;
			bleSend(fdUart, COMMAND_NAVI_DIRECTION, NAVIDIR_ARRIVED);
			sprintf(buff, "Arrived\r\n");
			write(fdUart, buff, strlen(buff));
			break;
			
		case NAVIDIR_LOWER_LEFT:
			std::cout << "Turn lower left" << std::endl;
			bleSend(fdUart, COMMAND_NAVI_DIRECTION, NAVIDIR_LOWER_LEFT);
			sprintf(buff, "Turn lower left\r\n");
			write(fdUart, buff, strlen(buff));
			break;
			
		case NAVIDIR_UPPER_LEFT:
			std::cout << "Turn upper left" << std::endl;
			bleSend(fdUart, COMMAND_NAVI_DIRECTION, NAVIDIR_UPPER_LEFT);
			sprintf(buff, "Turn upper left\r\n");
			write(fdUart, buff, strlen(buff));
			break;
			
		case NAVIDIR_LEFT:
			std::cout << "Turn left" << std::endl;
			bleSend(fdUart, COMMAND_NAVI_DIRECTION, NAVIDIR_LEFT);
			sprintf(buff, "Turn left\r\n");
			write(fdUart, buff, strlen(buff));
			break;
			
		case NAVIDIR_UPPER_RIGHT:
			std::cout << "Turn upper right" << std::endl;
			bleSend(fdUart, COMMAND_NAVI_DIRECTION, NAVIDIR_UPPER_RIGHT);
			sprintf(buff, "Turn upper right\r\n");
			write(fdUart, buff, strlen(buff));
			break;
			
		case NAVIDIR_RIGHT:
			std::cout << "Turn right" << std::endl;
			bleSend(fdUart, COMMAND_NAVI_DIRECTION, NAVIDIR_RIGHT);
			sprintf(buff, "Turn right\r\n");
			write(fdUart, buff, strlen(buff));
			break;
			
		case NAVIDIR_LOWER_RIGHT:
			std::cout << "Turn lower right" << std::endl;
			bleSend(fdUart, COMMAND_NAVI_DIRECTION, NAVIDIR_LOWER_RIGHT);
			sprintf(buff, "Turn lower right\r\n");
			write(fdUart, buff, strlen(buff));
			break;
			
		case NAVIDIR_LEFT_U_TURN:
			std::cout << "U Turn - left" << std::endl;
			bleSend(fdUart, COMMAND_NAVI_DIRECTION, NAVIDIR_LEFT_U_TURN);
			sprintf(buff, "U Turn - left\r\n");
			write(fdUart, buff, strlen(buff));
			break;
			
		case NAVIDIR_RIGHT_U_TURN:
			std::cout << "U Turn - right" << std::endl;
			bleSend(fdUart, COMMAND_NAVI_DIRECTION, NAVIDIR_RIGHT_U_TURN);
			sprintf(buff, "U Turn - right\r\n");
			write(fdUart, buff, strlen(buff));
			break;
			
		default:
			std::cout << "Incorrect direction" << std::endl;
			break;
	}
}

int main(int argc, char** argv)
{
	int fdUart;	
	char buff[128];
	
	if( argc != 2 )
	{
		printf("USAGE: uart_transmit UART_PORT\r\n");
		return -1;
	}

	fdUart = uartOpen(argv[1]);
	uartSetSpeed(fdUart, 115200);

	if (uartSetParity(fdUart,8,1,'N') == -1)
	{
		printf("Set Parity Error\n");
		return -1;
	}
	else
	{
		printf("%s connected\r\n", argv[1]);
	}
	
	egt::Application app(argc, argv);
	egt::experimental::UiLoader loader;
	
	auto window = std::static_pointer_cast<egt::Window>(loader.load("file:ui.xml"));
	
	auto btnConnect = window->find_child<egt::ImageButton>("btnConnect");
	auto btnDisconnect = window->find_child<egt::ImageButton>("btnDisconnect");
	btnDisconnect->disable();
	auto btnExit = window->find_child<egt::ImageButton>("btnExit");
	
	auto btnL = window->find_child<egt::ImageButton>("btnL");
	auto btnR = window->find_child<egt::ImageButton>("btnR");
	auto btnUL = window->find_child<egt::ImageButton>("btnUL");
	auto btnUR = window->find_child<egt::ImageButton>("btnUR");
	auto btnLL = window->find_child<egt::ImageButton>("btnLL");
	auto btnLR = window->find_child<egt::ImageButton>("btnLR");
	auto btnUTL = window->find_child<egt::ImageButton>("btnUTL");
	auto btnUTR = window->find_child<egt::ImageButton>("btnUTR");
	auto btnA = window->find_child<egt::ImageButton>("btnA");
	
	btnUL->disable();
	btnUR->disable();
	btnL->disable();
	btnR->disable();
	btnLL->disable();
	btnLR->disable();
	btnUTL->disable();
	btnUTR->disable();
	btnA->disable();
	
	btnConnect->on_click([&](egt::Event&)
	{
		std::cout << "Connect" << std::endl;
		btnDisconnect->enable();
		btnConnect->disable();
		
		btnUL->enable();
		btnUR->enable();
		btnL->enable();
		btnR->enable();
		btnLL->enable();
		btnLR->enable();
		btnUTL->enable();
		btnUTR->enable();
		btnA->enable();
		
		bleConnect(fdUart);
		std::cout << "BLE (" << fdUart << ")" << std::endl;
	});
	
	btnDisconnect->on_click([&](egt::Event&)
	{
		std::cout << "Disconnect" << std::endl;
		btnDisconnect->disable();
		btnConnect->enable();
		
		btnUL->disable();
		btnUR->disable();
		btnL->disable();
		btnR->disable();
		btnLL->disable();
		btnLR->disable();
		btnUTL->disable();
		btnUTR->disable();
		btnA->disable();
		
		bleDisconnect(fdUart);
		std::cout << "BLE (" << fdUart << ")" << std::endl;
	});
	
	btnExit->on_click([&](egt::Event&)
	{
		exit(0);
	});
	
	btnL->on_click([&](egt::Event&)
	{
		btnProcess(NAVIDIR_LEFT, fdUart);
	});
	
	btnR->on_click([&](egt::Event&)
	{
		btnProcess(NAVIDIR_RIGHT, fdUart);
	});
	
	btnUL->on_click([&](egt::Event&)
	{
		btnProcess(NAVIDIR_UPPER_LEFT, fdUart);
	});
	
	btnUR->on_click([&](egt::Event&)
	{
		btnProcess(NAVIDIR_UPPER_RIGHT, fdUart);
	});
	
	btnLL->on_click([&](egt::Event&)
	{
		btnProcess(NAVIDIR_LOWER_LEFT, fdUart);
	});
	
	btnLR->on_click([&](egt::Event&)
	{
		btnProcess(NAVIDIR_LOWER_RIGHT, fdUart);
	});
	
	btnUTL->on_click([&](egt::Event&)
	{
		btnProcess(NAVIDIR_LEFT_U_TURN, fdUart);
	});
	
	btnUTR->on_click([&](egt::Event&)
	{
		btnProcess(NAVIDIR_RIGHT_U_TURN, fdUart);
	});
	
	btnA->on_click([&](egt::Event&)
	{
		btnProcess(NAVIDIR_ARRIVED, fdUart);
	});
	
	window->show();

    return app.run();
}
