//----------------------------------------------------------
// JAI Camera Class
// JAI SDK 3.0.1.4
//----------------------------------------------------------
// Programmed by William Kim
//----------------------------------------------------------
// Last Update : 2017-04-17 19:10
// Modified by William Kim
//----------------------------------------------------------
#pragma once

#include <jai_factory.h>
#pragma comment (lib,"Jai_Factory")

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

namespace JAI_STANDARD{

//----- enum type -----//
enum USER {USER_Default=0, USER_UserSet1, USER_UserSet2, USER_UserSet3};
enum TRGMODE {TRG_On=0, TRG_Off};
enum TRGSRC {SRC_Line5, SRC_Line6, SRC_SW, SRC_Output0, SRC_Output1, SRC_Output2, SRC_Output3, SRC_PG0, SRC_PG1, SRC_PG2, SRC_PG3, SRC_NAND1, SRC_NAND2, SRC_ACTION1, SRC_ACTION2, SRC_NOTCONNECTED};
enum TRGOVL {OVL_Off=0, OVL_ReadOut, OVL_PreFrm};
enum EXPMODE {EXP_Timed=0, EXP_PWC};
enum ACQMODE {ACQ_CNT=0, ACQ_SINGLE, ACQ_MULTI};

class CJaiCamera
{
public:
	CJaiCamera(void);
	~CJaiCamera(void);
public :
	//******************************************************************************************************************
	/// \brief					System�� Device ���� Ȯ�� �Լ�.
	/// \param [out] nValue		Device ���� Ȯ��.
	/// \param bool				��� ��ȯ.
	static bool GetNumberOfDevices(int &nValue);
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
	static bool GetDeviceIPAddress(int nDvIdx, CString &strValue);
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
	static bool GetDeviceDefinedName(int nDvIdx, CString &strValue);
	//******************************************************************************************************************
	/// \brief					Ư�� Device�� Serial Number Ȯ�� �Լ�.
	/// \param [in] nDvIdx		Device Index.
	/// \param [out] strValue	Device Serial Number Ȯ��.
	/// \param bool				��� ��ȯ.
	static bool GetDeviceSerialNumber(int nDvIdx, CString &strValue);
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
	bool SetAcquisitionMode(ACQMODE Mode);
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

	//----- Ȯ�� �� ��ȯ �Լ� -----//
	CString GetLastErrorMessage() { return m_strErrMsg; }
	int GetWidth() { return m_nWidth; }
	int GetHeight() { return m_nHeight; }
	int GetBpp() { return m_nBpp; }
	bool IsConnected() { return m_isConnected; }
	bool IsActive() { return m_isActived; }
	bool GetDeviceUserID(CString &strValue);				// Device User ID ��ȯ.
	bool GetDeviceModelName(CString &strValue);				// Device Model Name ��ȯ.
	bool GetSerialNumber(bool bGigE, CString &strValue);	// Serial Number ��ȯ.
	bool GetOffsetX(int &nValue);							// Offset X ��ȯ.
	bool GetOffsetY(int &nValue);							// Offset Y ��ȯ.
	bool GetAcquisitionMode(CString &strValue);				// Acquisition Mode ��ȯ.
	bool GetAcquisitionFrameRate(double &dValue);			// Frame Rate ��ȯ.
	bool GetTriggerMode(CString &strValue);					// Trigger Mode ��ȯ.
	bool GetTriggerSource(CString &strValue);				// Trigger Source ��ȯ.
	bool GetExposureMode(CString &strValue);				// Exposure Mode ��ȯ.
	bool GetExposureTimeRaw(int &nValue);					// Exposure Time ��ȯ.
	bool GetPixelFormat(CString &strValue);					// Pixel Format ��ȯ.
	CString GetInterface() { return m_strInterface; }
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
	//******************************************************************************************************************
	/// \brief					User Selector ���� �Լ�.
	/// \param [in] Mode		Default / UserSet1 �Է�.
	/// \param bool				��� ��ȯ.
	bool SetUserSetSelector(USER User);

	HANDLE GetHandleGrabDone() { return m_hGrabDone; }
	void ResetHandleGrabDone() { ResetEvent(m_hGrabDone); }
private :
	//FACTORY_HANDLE	m_hFactory;
	CAM_HANDLE      m_hCamera;
	THRD_HANDLE     m_hThread;
	
	J_tIMAGE_INFO   m_ImgColor;
	HANDLE			m_hGrabDone;
	BYTE*			m_pbyBuffer;
	BITMAPINFO*		m_pBitmapInfo;

	CString m_strInterface;
	CString m_strErrMsg;

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

	
	CString GetErrorMsg(J_STATUS_TYPE ErrCode);

	bool OpenFactory();
	bool CloseFactory();
	void StreamCBFunc(J_tIMAGE_INFO * pAqImageInfo);

	bool GetWidth(int &nValue);
	bool GetHeight(int &nValue);
	bool GetBpp(int &nValue);

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