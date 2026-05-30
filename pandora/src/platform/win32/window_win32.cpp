#include "window_win32.h"

namespace Pandora {

	static bool s_IsGLFWInitialized = false;

	Window* Window::Create(const WindowProps& props)
	{
		return new WindowWin32(props);
	}

	WindowWin32::WindowWin32(const WindowProps& props)
	{
		Init(props);
	}

	WindowWin32::~WindowWin32()
	{
		Terminate();
	}

	void WindowWin32::SetVSyncEnabled(bool value)
	{
		glfwSwapInterval(value);
		m_Data.IsVSyncEnabled = value;
	}

	void WindowWin32::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void WindowWin32::Init(const WindowProps& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Heigth = props.Heigth;

		PANDORA_CORE_INFO("Creating window {0} ({1} : {2})", m_Data.Title, m_Data.Width, m_Data.Heigth);

		if (!s_IsGLFWInitialized) {
			int success = glfwInit();
			PANDORA_CORE_ASSERT(success, "Can't initialize GLFW");

			s_IsGLFWInitialized = true;
		}

		m_Window = glfwCreateWindow((int)m_Data.Width, (int)m_Data.Heigth, m_Data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		
		SetVSyncEnabled(true);
	}

	void WindowWin32::Terminate()
	{
		glfwDestroyWindow(m_Window);
	}

}