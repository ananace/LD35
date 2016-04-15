#pragma once

class ServerContainer
{
public:
	enum State
	{
		State_Invalid,
		State_Starting,
		State_Running,
		State_Stopping,
		State_Stopped
	};

	ServerContainer();
	ServerContainer(const ServerContainer&) = delete;
	~ServerContainer();

	ServerContainer& operator=(const ServerContainer&) = delete;

	bool init();
	void launch();

private:
	State mServerState;

	typedef void* ServerModuleHandle;
	ServerModuleHandle mServerModule;

	typedef void(*ServerInit_f)();
	ServerInit_f mServerInit;
	typedef void(*ServerRun_f)();
	ServerRun_f mServerRun;
	typedef void(*ServerSetBProp_f)(const char*, bool);
	ServerSetBProp_f mServerSetBProp;
	typedef void(*ServerSetIProp_f)(const char*, int);
	ServerSetIProp_f mServerSetIProp;
	typedef void(*ServerSetFProp_f)(const char*, float);
	ServerSetFProp_f mServerSetFProp;
	typedef bool(*ServerGetBProp_f)(const char*);
	ServerGetBProp_f mServerGetBProp;
	typedef int(*ServerGetIProp_f)(const char*);
	ServerGetIProp_f mServerGetIProp;
	typedef float(*ServerGetFProp_f)(const char*);
	ServerGetFProp_f mServerGetFProp;
};
