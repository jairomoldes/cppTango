//=============================================================================
//
// file :               DServerSignal.h
//
// description :        Include for the DServer class. This class implements
//                      all the commands which are available for device
//			of the DServer class. There is one device of the
//			DServer class for each device server process
//
// project :            TANGO
//
// author(s) :          A.Gotz + E.Taurel
//
// Copyright (C) :      2004,2005,2006,2007,2008,2009,2010,2011
//						European Synchrotron Radiation Facility
//                      BP 220, Grenoble 38043
//                      FRANCE
//
// This file is part of Tango.
//
// Tango is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// Tango is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with Tango.  If not, see <http://www.gnu.org/licenses/>.
//
// $Revision$
//
// $Log$
// Revision 3.9  2010/09/09 13:45:22  taurel
// - Add year 2010 in Copyright notice
//
// Revision 3.8  2009/01/21 12:49:03  taurel
// - Change CopyRights for 2009
//
// Revision 3.7  2008/10/06 15:01:09  taurel
// - Changed the licensing info from GPL to LGPL
//
// Revision 3.6  2008/10/03 06:52:31  taurel
// - Add some licensing info in each files
//
// Revision 3.5  2008/04/04 14:25:02  jensmeyer
// Added the necessary signal definitions for FreeBSD __freebsd__
//
// Revision 3.4  2008/02/28 12:29:31  jensmeyer
// Added signal definitions for MacOSX (__darwin__).
//
// Revision 3.3  2007/04/20 14:40:34  taurel
// - Ported to Windows 64 bits x64 architecture
//
// Revision 3.2  2006/01/20 08:22:29  taurel
// - Added necessary changes to support Device server written in Python
//
// Revision 3.1  2004/07/07 08:40:11  taurel
//
// - Fisrt commit after merge between Trunk and release 4 branch
// - Add EventData copy ctor, asiignement operator and dtor
// - Add Database and DeviceProxy::get_alias() method
// - Add AttributeProxy ctor from "device_alias/attribute_name"
// - Exception thrown when subscribing two times for exactly yhe same event
//
// Revision 3.0.4.2  2004/04/07 11:22:10  taurel
// - Add some import/export declaration for Windows DLL
// - Add test on minor code for the CORBA::IMP_LIMIT exception before
//   printing it
//
// Revision 3.0.4.1  2004/03/09 16:36:36  taurel
// - Added HP aCC port (thanks to Claudio from Elettra)
// - Some last small bugs fixes
//
// Revision 3.0  2003/03/25 16:43:18  taurel
// Many changes for Tango release 3.0 including
// - Added full logging features
// - Added asynchronous calls
// - Host name of clients now stored in black-box
// - Three serialization model in DS
// - Fix miscellaneous bugs
// - Ported to gcc 3.2
// - Added ApiUtil::cleanup() and destructor methods
// - Some internal cleanups
// - Change the way how TangoMonitor class is implemented. It's a recursive
//   mutex
//
// Revision 2.8  2002/12/16 12:07:19  taurel
// No change in code at all but only forgot th emost important line in
// list of updates in the previous release :
// - Change underlying ORB from ORBacus to omniORB
//
// Revision 2.7  2002/12/16 10:16:22  taurel
// - New method get_device_list() in Util class
// - Util::get_class_list takes DServer device into account
// - Util::get_device_by_name() takes DServer device into account
// - Util::get_device_list_by_class() takes DServer device into account
// - New parameter to the attribute::set_value() method to enable CORBA to free
// memory allocated for the attribute
//
// Revision 2.6  2002/10/17 07:43:06  taurel
// Fix bug in history stored by the polling thread :
// - We need one copy of the attribute data to build an history!!! It is true
// also for command which return data created by the DeviceImpl::create_xxx
// methods. Chnage in pollring.cpp/pollring.h/dserverpoll.cpp/pollobj.cpp
// and pollobj.h
//
// Revision 2.5  2002/10/15 11:27:19  taurel
// Fix bugs in device.cpp file :
// - Protect the state and status CORBA attribute with the device monitor
// Add the "TgLibVers" string as a #define in tango_config.h
//
// Revision 2.4  2002/08/12 15:06:54  taurel
// Several big fixes and changes
//   - Remove HP-UX specific code
//   - Fix bug in polling alogorithm which cause the thread to enter an infinite
//     loop (pollthread.cpp)
//   - For bug for Win32 device when trying to set attribute config
//     (attribute.cpp)
//
// Revision 2.3  2002/07/02 15:22:24  taurel
// Miscellaneous small changes/bug fixes for Tango CPP release 2.1.0
//     - classes reference documentation now generated using doxygen instead of doc++
//     - A little file added to the library which summarizes version number.
//       The RCS/CVS "ident" command will now tells you that release library x.y.z is composed
//       by C++ client classes set release a.b and C++ server classes set release c.d
//     - Fix incorrect field setting for DevFailed exception re-thrown from a CORBA exception
//     - It's now not possible to poll the Init command
//     - It's now possible to define a default class doc. per control system
//       instance (using property)
//     - The test done to check if attribute value has been set before it is
//       returned to caller is done only if the attribute quality is set to VALID
//     - The JTCInitialize object is now stored in the Util
//     - Windows specific : The tango.h file now also include winsock.h
//
// Revision 2.2  2002/04/30 10:50:41  taurel
// Don't check alarm on attribute if attribute quality factor is INVALID
//
// Revision 2.1  2002/04/29 12:24:03  taurel
// Fix bug in attribute::set_value method and on the check against min and max value when writing attributes
//
// Revision 2.0  2002/04/09 14:45:10  taurel
// See Tango WEB pages for list of changes
//
// Revision 1.6  2001/10/08 09:03:13  taurel
// See tango WEB pages for list of changes
//
// Revision 1.5  2001/07/04 12:27:10  taurel
// New methods re_throw_exception(). Read_attributes supports AllAttr mnemonic A new add_attribute()method in DeviceImpl class New way to define attribute properties New pattern to prevent full re-compile For multi-classes DS, it is now possible to use the Util::get_device_by_name() method in device constructor Adding << operator ovebloading Fix devie CORBA ref. number when device constructor sends an excep.
//
// Revision 1.4  2001/05/04 09:28:14  taurel
// Fix bugs in DServer::restart() method and in Util::get_device_by_name() method
//
// Revision 1.3  2001/03/30 08:03:45  taurel
// Fix bugs in attributes. For linux, add signal_handler in its own thread, change the way to kill server. For all system, change DevRestart philosophy.
//
// Revision 1.2  2001/03/09 08:20:16  taurel
// Fix bug in the MultiClassAttribute::init_class_attribute() method. Also remove the DbErr_DeviceNotDefined define.
//
// Revision 1.1.1.1  2001/02/27 08:46:20  taurel
// Imported sources
//
// Revision 1.3  2000/04/13 10:40:41  taurel
// Added attribute support
//
// Revision 1.2  2000/02/04 11:00:15  taurel
// Just update revision number
//
// Revision 1.1.1.1  2000/02/04 10:58:28  taurel
// Imported sources
//
//=============================================================================

#ifndef _DSERVERSIGNAL_H
#define _DSERVERSIGNAL_H

#include <tango.h>
#include <signal.h>

namespace Tango
{

//=============================================================================
//
//			The DServerSignal class
//
// description :	Class to implement all data members and commands for 
//			signal management in a TANGO device server.
//
//=============================================================================

#if ((defined sun) || defined (_TG_WINDOWS_) || \
    (defined __darwin__) || (defined __freebsd__)) 
#define		_NSIG		NSIG
#endif


typedef struct
{
	vector <DeviceClass *>	registered_classes;
	vector <DeviceImpl *>	registered_devices;
	bool			own_handler;
}
DevSigAction;

class DServerSignal:public TangoMonitor
{
public :
	TANGO_IMP_EXP static DServerSignal *instance();
	~DServerSignal() {};

#if (defined __linux)
	void register_class_signal(long, bool, DeviceClass *);
	void register_dev_signal(long, bool, DeviceImpl *);
	
	void register_handler(long,bool);
	pid_t get_sig_thread_pid();
#else	
	void register_class_signal(long, DeviceClass *);
	void register_dev_signal(long, DeviceImpl *);
	
	void register_handler(long);
#endif
	
	void unregister_class_signal(long, DeviceClass *);
	void unregister_class_signal(DeviceClass *);
	void unregister_dev_signal(long, DeviceImpl *);
	void unregister_dev_signal(DeviceImpl *);
			
	void unregister_handler(long);
		
	static void main_sig_handler(int);
		
	class ThSig: public omni_thread
	{
		DServerSignal *ds;
	public:
		ThSig(DServerSignal *d):ds(d),my_pid(0),th_data_created(false) {}
		virtual ~ThSig() {}
		
		TangoSys_Pid my_pid;
		bool th_data_created;
#ifndef _TG_WINDOWS_
		pthread_t my_thread;
#endif
		void *run_undetached(void *);
		void start() {start_undetached();}
	};
	friend class ThSig;
	ThSig *sig_th;

protected :
	DServerSignal();
	static DevSigAction		reg_sig[_NSIG];
	
	bool				sig_to_install;
	bool				sig_to_remove;
	int				inst_sig;
	int 				rem_sig;
#ifdef _TG_WINDOWS_
	static HANDLE			win_ev;
	static int			win_signo;
#endif
		
private:
	static DServerSignal *_instance;
	vector<DeviceImpl *>::iterator find_device(long, DeviceImpl *);
	vector<DeviceImpl *>::iterator find_delayed_device(long, DeviceImpl *);
	
	vector<DeviceClass *>::iterator find_class(long, DeviceClass *);
	vector<DeviceClass *>::iterator find_delayed_class(long, DeviceClass *);

#ifdef _TG_WINDOWS_
	static inline bool auto_signal(long s)
	{
		if ((s==SIGINT) || (s==SIGTERM) || (s==SIGABRT) || (s==SIGBREAK))
			return true;
		else
			return false;
	}	
#else
	static inline bool auto_signal(long s)
	{
		if ((s==SIGQUIT) || (s==SIGINT) || (s==SIGHUP) || (s==SIGTERM))
			return true;
		else 
			return false;
	}	
#endif

#ifdef sun
	static inline bool ign_signal(long s)
	{
		if ((s==SIGCHLD) || (s==SIGPWR) || (s==SIGWINCH) || (s==SIGURG) || (s==SIGCONT) || (s==SIGFREEZE))
			return true;
		else 
			return false;
	}
#endif


#if (defined __linux || defined __darwin__ || defined __freebsd__)
	static inline bool auth_signal(long s)
	{
		if ((s==SIGUSR1) || (s==SIGUSR2))
			return false;
		else
			return true;
	}
#endif
#if ((defined sun) || (defined __hpux))
	static inline bool auth_signal(long s) {return true;}
#endif
#ifdef _TG_WINDOWS_
	static inline bool auth_signal(long s) {return true;}
#endif
	
	static string 			sig_name[_NSIG];	

};

} // End of namespace Tango


#endif