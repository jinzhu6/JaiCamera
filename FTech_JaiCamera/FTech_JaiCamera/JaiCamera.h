//----------------------------------------------------------
// JAI Camera Class
// JAI SDK 2.1.6.8 version / SDK 1.4.1 version
//----------------------------------------------------------
// Programmed by William Kim
//----------------------------------------------------------
// Last Update : 2017-01-11 19:24
// Modified by William Kim
//----------------------------------------------------------

#pragma once

#include <jai_factory.h>
#pragma comment (lib,"Jai_Factory")

#define NODE_WIDTH			(int8_t*)"Width"
#define NODE_HEIGHT			(int8_t*)"Height"
#define NODE_PIXELFORMAT	(int8_t*)"PixelFormat"
#define NODE_USERID			(int8_t*)"DeviceUserID"
#define NODE_MODELNAME		(int8_t*)"DeviceModelName"
#define NODE_DEVICEID		(int8_t*)"DeviceID"
#define NODE_OFFSETX		(int8_t*)"OffsetX"
#define NODE_OFFSETY		(int8_t*)"OffsetY"
#define NODE_ACQMODE		(int8_t*)"AcquisitionMode"
#define NODE_ACQFPS			(int8_t*)"AcquisitionFrameRate"
#define NODE_TRGMODE		(int8_t*)"TriggerMode"
#define NODE_TRGSRC			(int8_t*)"TriggerSource"
#define NODE_EXPMODE		(int8_t*)"ExposureMode"
#define NODE_EXPTIME		(int8_t*)"ExposureTimeRaw"
#define NODE_ACQSTART		(int8_t*)"AcquisitionStart"
#define NODE_ACQSTOP		(int8_t*)"AcquisitionStop"

namespace JAI_STANDARD{

//----- enum type -----//
enum USER {USER_Default=0, USER_UserSet1, USER_UserSet2, USER_UserSet3};
enum TRGMODE {TRG_On=0, TRG_Off};
enum TRGSRC {SRC_Line5, SRC_Line6, SRC_SW, SRC_Output0, SRC_Output1, SRC_Output2, SRC_Output3, SRC_PG0, SRC_PG1, SRC_PG2, SRC_PG3, SRC_NAND1, SRC_NAND2, SRC_ACTION1, SRC_ACTION2, SRC_NOTCONNECTED};
enum TRGOVL {OVL_Off=0, OVL_ReadOut, OVL_PreFrm};
enum EXPMODE {EXP_Timed=0, EXP_PWC};

class CJaiSystem
{
public :
	CJaiSystem(void);
	~CJaiSystem(void);

public :
	bool SearchDevices(int &nValue);
	bool GetManufacture(int nIdx, CString &strVendor);
	bool GetInterface(int nIdx, CString &strInterface);
	bool GetModelName(int nIdx, CString &strModel);
	bool GetSerialNumber(int nIdx, CString &strSerial);
	bool GetIPAddress(int nIdx, CString &strIP);

private :
	FACTORY_HANDLE m_hFactory;
};
class CJaiCamera
{
public:
	CJaiCamera(void);
	~CJaiCamera(void);

public :
	bool OnConnect(int nIdx, bool bColorConvert);
	bool OnDisconnect();

	//----- ���� ��� ���� -----//
	bool OnStartAcquisition();
	bool OnStopAcquisition();

	//----- ���� ��� ��� ���� -----//
	bool SetContinuousMode();
	bool SetSoftTriggerMode();
	bool SetHardTriggerMode();
	bool OnTriggerEvent();

	//----- ���� ����-----//
	bool OnSaveImage(CString strPath);	// �̹��� ����.

	//----- ���� ���� / �ҷ����� -----//
	bool SetUserSetSelector(USER User);
	bool OnUserSetSave();
	bool OnUserSetLoad();

	//----- ȭ��Ʈ�뷱�� -----//
	bool OnCalculateWhiteBalance();

	//----- Ȯ�� �� ��ȯ �Լ� -----//
	bool IsConnected() { return m_isConnected; }
	bool IsActive() { return m_isActived; }
	bool GetDeviceUserID(CString &strValue);				// Device User ID ��ȯ.
	bool GetDeviceModelName(CString &strValue);				// Device Model Name ��ȯ.
	bool GetSerialNumber(CString &strValue);				// Serial Number ��ȯ.
	bool GetOffsetX(int &nValue);							// Offset X ��ȯ.
	bool GetOffsetY(int &nValue);							// Offset Y ��ȯ.
	bool GetAcquisitionMode(CString &strValue);				// Acquisition Mode ��ȯ.
	bool GetAcquisitionFrameRate(double &dValue);			// Frame Rate ��ȯ.
	bool GetTriggerMode(CString &strValue);					// Trigger Mode ��ȯ.
	bool GetTriggerSource(CString &strValue);				// Trigger Source ��ȯ.
	bool GetExposureMode(CString &strValue);				// Exposure Mode ��ȯ.
	bool GetExposureTimeRaw(int &nValue);					// Exposure Time ��ȯ.
	bool GetPixelFormat(CString &strValue);					// Pixel Format ��ȯ.
	bool GetWidth(int &nValue);
	bool GetHeight(int &nValue);
	bool GetBpp(int &nValue);
	BYTE* GetImageBuffer() { return m_pbyBuffer; }			// Buffer ��ȯ.

	//----- ���� �Լ� -----//
	bool SetDeviceUserID(CString strValue);					// Device User ID ����.
	bool SetOffsetX(int nValue);							// Offset X ����.
	bool SetOffsetY(int nValue);							// Offset Y ����.
	bool SetAcquisitionFrameRate(double dValue);			// Frame Rate ����.
	bool SetAcquisitionMode(CString strValue);				// Acquistiion Mode ����.
	bool SetTriggerMode(TRGMODE Mode);						// Trigger Mode ����.
	bool SetTriggerSource(TRGSRC Src);						// Trigger Source ����.
	bool SetTriggerOverlap(TRGOVL Ovl);						// Trigger Overlap ����.
	bool SetExposureMode(EXPMODE Mode);						// Exposure Mode ����.
	bool SetExposureTime(int nValue);					// Exposure Time ����.

	HANDLE GetHandleGrabDone() { return m_hGrabDone; }
	void ResetHandleGrabDone() { ResetEvent(m_hGrabDone); }
private :
	FACTORY_HANDLE	m_hFactory;
	CAM_HANDLE      m_hCamera;
	THRD_HANDLE     m_hThread;
	
	J_tIMAGE_INFO   m_ImgColor;
	HANDLE			m_hGrabDone;
	BYTE*			m_pbyBuffer;
	BITMAPINFO*		m_pBitmapInfo;

	int	m_nWidth;
	int	m_nHeight;
	int	m_nBpp;
	int	m_nGainR;
	int	m_nGainG;
	int	m_nGainB;
	bool m_isConnected;
	bool m_isActived;
	bool m_isColorConvert;
	bool m_is3CCD;

	bool OpenFactory();
	bool CloseFactory();
	void StreamCBFunc(J_tIMAGE_INFO * pAqImageInfo);
	void OnCreateBmpInfo(int nWidth, int nHeight, int nBpp);

	bool GetValueString(int8_t* pNodeName, CString &strValue);
	bool SetValueString(int8_t* pNodeName, CString strValue);
	bool GetValueInt(int8_t* pNodeName, int &nValue);
	bool SetValueInt(int8_t* pNodeName, int nValue);
	bool GetValueDouble(int8_t* pNodeName, double &dValue);
	bool SetValueDouble(int8_t* pNodeName, double dValue);
	bool OnExecuteCommand(int8_t* pNodeName);
};

#ifdef _UNICODE
static bool CStringToChar(const CString strIn, char* pchOut)
{
	if (pchOut == NULL) return false;

	size_t szCvt = 0;
	wcstombs_s(&szCvt, pchOut, strIn.GetLength()+1, strIn, _TRUNCATE);

	return true;
}
#else
static bool CStringToChar(CString strIn, char* pchOut)
{
	if (pchOut == NULL) return false;

	strcpy(pchOut, CT2A(strIn));

	return true;
}

#endif

}