#include "stdafx.h"
#include "KeyMgr.h"

CKeyMgr* CKeyMgr::m_pInstance = NULL;
bool CKeyMgr::KeyPressing(int iKey)
{
	if (GetAsyncKeyState(iKey) & 0x8000)
		return true;
	return false;
}

bool CKeyMgr::KeyDown(int iKey)
{
	if (GetAsyncKeyState(iKey) & 0x8000 && !m_bKeyState[iKey])
	{
		m_bKeyState[iKey] = !m_bKeyState[iKey];
		return true;
	}
	return false;
}

bool CKeyMgr::KeyUp(int iKey)
{
	if (!(GetAsyncKeyState(iKey) & 0x8000) && m_bKeyState[iKey])
	{
		m_bKeyState[iKey] = !m_bKeyState[iKey];
		return true;
	}
	return false;
}

void CKeyMgr::UpdateState()
{
	for (int i = 0; i < VK_MAX; ++i)
	{
		if (!m_bKeyState[i] && (GetAsyncKeyState(i) & 0x8000))	//������ �ȴ��ȴµ� ���� ������ ��� �ٲ�
			m_bKeyState[i] = !m_bKeyState[i];
		if (m_bKeyState[i] && !(GetAsyncKeyState(i) & 0x8000))	//������ �����µ� ���� �ȴ����� ��� �ٲ�
			m_bKeyState[i] = !m_bKeyState[i];
	}
}