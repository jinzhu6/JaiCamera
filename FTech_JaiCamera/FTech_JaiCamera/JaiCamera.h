//----------------------------------------------------------
// JAI Camera Class
// JAI SDK 3.0.1.4
//----------------------------------------------------------
// Programmed by William Kim
//----------------------------------------------------------
// Last Update : 2017-11-23 13:55
// Modified by William Kim
//----------------------------------------------------------
#pragma once

#include <jai_factory.h>
#pragma comment (lib,"Jai_Factory")

namespace JAI_SDK {

#define NODE_WIDTH				(int8_t*)"Width"
#define NODE_HEIGHT				(int8_t*)"Height"
#define NODE_PIXELFORMAT		(int8_t*)"PixelFormat"
#define NODE_USERID				(int8_t*)"DeviceUserID"
#define NODE_MODELNAME			(int8_t*)"DeviceModelName"
#define NODE_SERIALNUMBER_GIGE	(int8_t*)"DeviceSerialNumber"
#define NODE_SERIALNUMBER_USB	(int8_t*)"DeviceID"
#define NODE_OFFSETX			(int8_t*)"OffsetX"
#define NODE_OFFSETY			(int8_t*)"OffsetY"
#define NODE_ACQMODE			(int8_t*)"AcquisitionMode"
#define NODE_ACQFPS				(int8_t*)"AcquisitionFrameRate"
#define NODE_TRGMODE			(int8_t*)"TriggerMode"
#define NODE_TRGSRC				(int8_t*)"TriggerSource"
#define NODE_EXPMODE			(int8_t*)"ExposureMode"
#define NODE_EXPTIME			(int8_t*)"ExposureTimeRaw"
#define NODE_ACQSTART			(int8_t*)"AcquisitionStart"
#define NODE_ACQSTOP			(int8_t*)"AcquisitionStop"
#define NODE_ACQMMODE			(int8_t*)"AcquisitionMode"
#define NODE_ACQMFRMCNT			(int8_t*)"AcquisitionFrameCount"
#define NODE_USERSETSELECTOR	(int8_t*)"UserSetSelector"
#define NODE_USERSETSAVE		(int8_t*)"UserSetSave"
#define NODE_USERSETLOAD		(int8_t*)"UserSetLoad"

//----- enum type -----//
typedef	enum { eDefault=0, eUserSet1, eUserSet2, eUserSet3 } EUserSet;
typedef	enum { eLine5=0, eLine6, eSoftware, eOutput0, eOutput1, eOutput2, eOutput3, ePG0, ePG1, ePG2, ePG3, eNAND1, eNAND2, eAction1, eAction2, eNotConnected } ETrgSrc;
typedef	enum { eOff=0, eReadOut, ePreviousFrame } ETrgOvl;
typedef	enum { eTimed=0, eTriggerWidth } EExpMode;
typedef	enum { eContinuous=0, eSingleFrame, eMultiFrame } EAcqMode ;

class CJaiCamera
{
public:
	CJaiCamera(void);
	~CJaiCamera(void);
public :
	//******************************************************************************************************************
	/// \brief					System�� Device ���� Ȯ�� �Լ�.
	/// \param [out] nDvCnt		Device ���� Ȯ��.
	/// \param bool				��� ��ȯ.
	static bool GetDeviceCount(int &nDvCnt);
	//******************************************************************************************************************
	/// \brief					Ư�� Device�� Interface Name Ȯ�� �Լ�.
	/// \param [in] nDvIdx		Device Index �Է�.
	/// \param [out] strvalue	Interface Name Ȯ��.
	/// \param bool				��� ��ȯ.
	static bool GetInterfaceName(int nDvIdx, CString &strValue);
	//******************************************************************************************************************
	/// \brief					Ư�� Device�� Interface Type Ȯ�� �Լ�.
	/// \param [in] nDvIdx		Device Index �Է�.
	/// \param [out] strvalue	Interface Type Ȯ��.
	/// \param bool				��� ��ȯ.
	static bool GetInterfaceType(int nDvIdx, CString &strValue);
	//******************************************************************************************************************
	/// \brief					Ư�� Device�� IP Address Ȯ�� �Լ�.
	/// \param [in] nDvIdx		Device Index �Է�.
	/// \param [out] strvalue	IP Address Ȯ��.
	/// \param bool				��� ��ȯ.
	static bool GetDeviceIPAddr(int nDvIdx, CString &strValue);
	//******************************************************************************************************************
	/// \brief					Ư�� Device�� Model Name Ȯ�� �Լ�.
	/// \param [in] nDvIdx		Device Index.
	/// \param [out] strValue	Device Model Name Ȯ��.
	/// \param bool				��� ��ȯ.
	static bool GetDeviceName(int nDvIdx, CString &strValue);
	//******************************************************************************************************************
	/// \brief					Ư�� Device�� User Defined Name Ȯ�� �Լ�.
	/// \param [in] nDvIdx		Device Index.
	/// \param [out] strValue	Device User Defined Name Ȯ��.
	/// \param bool				��� ��ȯ.
	static bool GetDeviceUserID(int nDvIdx, CString &strValue);
	//******************************************************************************************************************
	/// \brief					Ư�� Device�� Serial Number Ȯ�� �Լ�.
	/// \param [in] nDvIdx		Device Index.
	/// \param [out] strValue	Device Serial Number Ȯ��.
	/// \param bool				��� ��ȯ.
	static bool GetDeviceSN(int nDvIdx, CString &strValue);
public :
	//******************************************************************************************************************
	/// \brief					Ư�� Device�� �����ϴ� �Լ�.
	/// \param [in] nDvIdx		Device Index.
	/// \param bool				��� ��ȯ.
	bool OnConnect(int nDvIdx);
	//******************************************************************************************************************
	/// \brief					�Է��� Device User ID�� ������ ī�޶� �����ϴ� �Լ�.
	/// \param [in] strUserID	Ư�� Device User ID�� �Է�.
	/// \param bool				��� ��ȯ.
	bool OnConnectID(CString strUserID);
	//******************************************************************************************************************
	/// \brief					�Է��� IP Address�� ������ ī�޶� �����ϴ� �Լ�.
	/// \param [in] strIPAddressƯ�� IP Address�� �Է�. ('.'�� �����ؾ� �Ѵ�.)
	/// \param bool				��� ��ȯ.
	bool OnConnectIP(CString strIPAddress);
	//******************************************************************************************************************
	/// \brief					ī�޶� �����ϴ� �Լ�.
	/// \param bool				��� ��ȯ.
	bool OnDisconnect();
	//******************************************************************************************************************
	/// \brief					���� ��� ���� �Լ�.
	/// \param bool				��� ��ȯ.
	bool OnStartAcquisition();
	//******************************************************************************************************************
	/// \brief					���� ��� ���� �Լ�.
	/// \param bool				��� ��ȯ.
	bool OnStopAcquisition();
	//******************************************************************************************************************
	/// \brief					Continuous Mode ���� �Լ�.
	/// \param bool				��� ��ȯ.
	bool SetContinuousMode();
	//******************************************************************************************************************
	/// \brief					Software Trigger Mode ���� �Լ�.
	/// \param bool				��� ��ȯ.
	bool SetSoftTriggerMode();
	//******************************************************************************************************************
	/// \brief					Hardware Trigger Mode ���� �Լ�.
	/// \param bool				��� ��ȯ.
	bool SetHardTriggerMode();
	//******************************************************************************************************************
	/// \brief					Software Trigger Event �߻� �Լ�.
	/// \param bool				��� ��ȯ.
	bool OnTriggerEvent();
	//******************************************************************************************************************
	/// \brief					Acquisition Mode ���� �Լ�.
	/// \param [in] Mode		Continuous / Single Frame / Multi Frame ���� ����.
	/// \param bool				��� ��ȯ.
	bool SetAcquisitionMode(EAcqMode eMode);
	//******************************************************************************************************************
	/// \brief					Multi Frame Count ���� �Լ�.
	/// \param [in] nValue		Count �Է�.
	/// \param bool				��� ��ȯ.
	bool SetMultiFrameCount(int nValue);
	//******************************************************************************************************************
	/// \brief					�̹��� ���� �Լ�.
	/// \param [in] strPath		���� ��� �Է�.
	/// \param bool				��� ��ȯ.
	bool OnSaveImage(CString strPath);
	//******************************************************************************************************************
	/// \brief					User Set ���� �Լ�.
	/// \param bool				��� ��ȯ.
	bool OnUserSetSave();
	//******************************************************************************************************************
	/// \brief					User Set �ҷ����� �Լ�.
	/// \param bool				��� ��ȯ.
	bool OnUserSetLoad();
	//******************************************************************************************************************
	/// \brief					Auto White Balance ���� �Լ�.
	/// \param bool				��� ��ȯ.
	bool OnCalculateWhiteBalance();
public :
	//******************************************************************************************************************
	/// \brief					Device ���� ���� Ȯ�� �Լ�.
	/// \param bool				��� ��ȯ.
	bool IsConnected() { return m_isConnected; }
	//******************************************************************************************************************
	/// \brief					���� ��� ���� Ȯ�� �Լ�.
	/// \param bool				��� ��ȯ.
	bool IsActive() { return m_isActived; }
	//******************************************************************************************************************
	/// \brief					Device User ID Ȯ�� �Լ�.
	/// \param [out] strValue	Device User ID Ȯ��.
	/// \param bool				��� ��ȯ.
	bool GetDeviceUserID(CString &strValue);
	//******************************************************************************************************************
	/// \brief					Device Model Name Ȯ�� �Լ�.
	/// \param [out] strValue	Device Model Name Ȯ��.
	/// \param bool				��� ��ȯ.
	bool GetDeviceModelName(CString &strValue);
	//******************************************************************************************************************
	/// \brief					Device Serial Number Ȯ�� �Լ�.
	/// \param [in] bGigE		GigE Device���� ���� �Լ�.
	/// \param [out] strValue	Device Serial Number Ȯ��.
	/// \param bool				��� ��ȯ.
	bool GetSerialNumber(bool bGigE, CString &strValue);
	//******************************************************************************************************************
	/// \brief					Offset X Ȯ�� �Լ�.
	/// \param [out] nValue		Offset X Ȯ��.
	/// \param bool				��� ��ȯ.
	bool GetOffsetX(int &nValue);
	//******************************************************************************************************************
	/// \brief					Offset Y Ȯ�� �Լ�.
	/// \param [out] nValue		Offset Y Ȯ��.
	/// \param bool				��� ��ȯ.
	bool GetOffsetY(int &nValue);
	//******************************************************************************************************************
	/// \brief					Acquisition Mode Ȯ�� �Լ�.
	/// \param [out] strValue	Acquisition Mode Ȯ��.
	/// \param bool				��� ��ȯ.
	bool GetAcquisitionMode(CString &strValue);
	//******************************************************************************************************************
	/// \brief					Frame Rate Ȯ�� �Լ�.
	/// \param [out] dValue		Frame Rate Ȯ��.
	/// \param bool				��� ��ȯ.
	bool GetAcquisitionFrameRate(double &dValue);
	//******************************************************************************************************************
	/// \brief					Trigger Mode Ȯ�� �Լ�.
	/// \param [out] strValue	Trigger Mode Ȯ��.
	/// \param bool				��� ��ȯ.
	bool GetTriggerMode(CString &strValue);
	//******************************************************************************************************************
	/// \brief					Trigger Source Ȯ�� �Լ�.
	/// \param [out] strValue	Trigger Source Ȯ��.
	/// \param bool				��� ��ȯ.
	bool GetTriggerSource(CString &strValue);
	//******************************************************************************************************************
	/// \brief					Exposure Mode Ȯ�� �Լ�.
	/// \param [out] strValue	Exposure Mode Ȯ��.
	/// \param bool				��� ��ȯ.
	bool GetExposureMode(CString &strValue);
	//******************************************************************************************************************
	/// \brief					Exposure Time Ȯ�� �Լ�.
	/// \param [out] nValue		Exposure Time Ȯ��.
	/// \param bool				��� ��ȯ.
	bool GetExposureTimeRaw(int &nValue);
	//******************************************************************************************************************
	/// \brief					Pixel Format Ȯ�� �Լ�.
	/// \param [out] strValue	Pixel Format Ȯ��.
	/// \param bool				��� ��ȯ.
	bool GetPixelFormat(CString &strValue);
	//******************************************************************************************************************
	/// \brief					������ ���� �޽��� Ȯ�� �Լ�.
	/// \param CString			������ ���� �޽��� ��ȯ.
	CString GetLastErrorMessage() { return m_strErrMsg; }
	//******************************************************************************************************************
	/// \brief					Width Ȯ�� �Լ�.
	/// \param int				��� ��ȯ.
	int  GetWidth()  { return m_nWidth;  }
	//******************************************************************************************************************
	/// \brief					Height Ȯ�� �Լ�.
	/// \param int				��� ��ȯ.
	int  GetHeight() { return m_nHeight; }
	//******************************************************************************************************************
	/// \brief					BPP Ȯ�� �Լ�.
	/// \param int				��� ��ȯ.
	int  GetBpp()	 { return m_nBpp; }
	//******************************************************************************************************************
	/// \brief					Grab Done Handle ��ȯ �Լ�.
	/// \param HANDLE			��� ��ȯ.
	HANDLE GetHandleGrabDone() { return m_hGrabDone; }
	//******************************************************************************************************************
	/// \brief					Grab Done Handle Reset �Լ�.
	/// \param void				��ȯ ����.
	void ResetHandleGrabDone() { ResetEvent(m_hGrabDone); }
	//******************************************************************************************************************
	/// \brief					Device�� Interface Type Ȯ�� �Լ�.
	/// \param CString			Interface Type ���ڿ� ��ȯ.
	CString GetInterface() { return m_strInterface; }
	//******************************************************************************************************************
	/// \brief					Image Buffer Ȯ�� �Լ�.
	/// \param BYTE*			Image Buffer Pointer ��ȯ.
	BYTE* GetImageBuffer() { return m_pbyBuffer; }
	//******************************************************************************************************************
	/// \brief					Device User ID ���� �Լ�.
	/// \param [in] strValue	Device User ID �Է�.
	/// \param bool				��� ��ȯ.
	bool SetDeviceUserID(CString strValue);
	//******************************************************************************************************************
	/// \brief					Offset X ���� �Լ�.
	/// \param [in] nValue		Offset X �Է�.
	/// \param bool				��� ��ȯ.
	bool SetOffsetX(int nValue);
	//******************************************************************************************************************
	/// \brief					Offset Y ���� �Լ�.
	/// \param [in] nValue		Offset Y �Է�.
	/// \param bool				��� ��ȯ.
	bool SetOffsetY(int nValue);
	//******************************************************************************************************************
	/// \brief					Frame Rate ���� �Լ�.
	/// \param [in] dValue		Frame Rate �Է�.
	/// \param bool				��� ��ȯ.
	bool SetAcquisitionFrameRate(double dValue);
	//******************************************************************************************************************
	/// \brief					Acquisition Mode ���� �Լ�.
	/// \param [in] strValue	Acquisition Mode �Է�.
	/// \param bool				��� ��ȯ.
	bool SetAcquisitionMode(CString strValue);
	//******************************************************************************************************************
	/// \brief					Trigger Mode ���� �Լ�.
	/// \param [in] bEnable		On / Off �Է�.
	/// \param bool				��� ��ȯ.
	bool SetTriggerMode(bool bEnable);
	//******************************************************************************************************************
	/// \brief					Trigger Source ���� �Լ�.
	/// \param [in] Src			Soft / Hard �Է�.
	/// \param bool				��� ��ȯ.
	bool SetTriggerSource(ETrgSrc eSrc);
	//******************************************************************************************************************
	/// \brief					Trigger Overlap ���� �Լ�.
	/// \param [in] Ovl			Off=0 / ReadOut / Pre Frame �Է�.
	/// \param bool				��� ��ȯ.
	bool SetTriggerOverlap(ETrgOvl eOvl);
	//******************************************************************************************************************
	/// \brief					Exposure Mode ���� �Լ�.
	/// \param [in] Mode		Timed / Trigger Width �Է�.
	/// \param bool				��� ��ȯ.
	bool SetExposureMode(EExpMode eMode);
	//******************************************************************************************************************
	/// \brief					Exposure Time ���� �Լ�.
	/// \param [in] nValue		Exposure Time �Է�.
	/// \param bool				��� ��ȯ.
	bool SetExposureTime(int nValue);
	//******************************************************************************************************************
	/// \brief					User Selector ���� �Լ�.
	/// \param [in] Mode		Default / UserSet1 �Է�.
	/// \param bool				��� ��ȯ.
	bool SetUserSetSelector(EUserSet eUser);
private :
	//FACTORY_HANDLE	m_hFactory;
	CAM_HANDLE      m_hCamera;		// Camera Handle.
	THRD_HANDLE     m_hThread;		// Thread Handle.
	J_tIMAGE_INFO   m_ImgColor;		// Bayer ��ȯ �� ���Ǵ� Info.
	HANDLE			m_hGrabDone;	// Grab Done Ȯ�� Handle.
	BYTE*			m_pbyBuffer;	// Image Buffer.
	BITMAPINFO*		m_pBitmapInfo;	// Image Bitmap Info.

	CString m_strInterface;	// Device�� Interface Ȯ�� ���ڿ�.
	CString m_strErrMsg;	// ������ ���� �޽���.

	int	m_nWidth;	// Image Width Size.
	int	m_nHeight;	// Image Height Size.
	int	m_nBpp;		// Image Bit Per Pixel ũ��.
	int	m_nGainR;	// White Balance R Gain.
	int	m_nGainG;	// White Balance G Gain.
	int	m_nGainB;	// White Balance B Gain.

	bool m_isConnected;		// Device ���� ���� Ȯ��.
	bool m_isActived;		// Acquisition ���� Ȯ��.
	bool m_isColorConvert;	// Bayer Conversion Ȯ��.
	bool m_is3CCD;			// 3CCd Ȯ��.

private :
	CString GetErrorMsg(J_STATUS_TYPE ErrCode);
	bool OpenFactory();
	bool CloseFactory();
	bool GetWidth(int &nValue);
	bool GetHeight(int &nValue);
	bool GetBpp(int &nValue);
	void StreamCBFunc(J_tIMAGE_INFO * pAqImageInfo);
	void OnCreateBmpInfo(int nWidth, int nHeight, int nBpp);

private :
	//******************************************************************************************************************
	/// \brief					Type���� Get/Set �ϴ� �Լ�.
	/// \param [in] pNodeName	�Ķ������ Node Name �Է�.
	/// \param [in]  Value		�Ķ������ �� �Է�.
	/// \param [out] Value		�Ķ������ �� Ȯ��.
	/// \param bool				��� ��ȯ.
	bool GetValueString(int8_t* pNodeName, CString &strValue);
	bool SetValueString(int8_t* pNodeName, CString strValue);
	bool GetValueInt(int8_t* pNodeName, int &nValue);
	bool SetValueInt(int8_t* pNodeName, int nValue);
	bool GetValueDouble(int8_t* pNodeName, double &dValue);
	bool SetValueDouble(int8_t* pNodeName, double dValue);
	bool OnExecuteCommand(int8_t* pNodeName);
};

}