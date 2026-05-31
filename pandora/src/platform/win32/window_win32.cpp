#include "window_win32.h"

#include "events/application_event.h"
#include "events/window_event.h"
#include "events/mouse_event.h"
#include "events/key_event.h"

namespace Pandora {

	static bool s_IsGLFWInitialized = false;

	static void GLFWErrorCallback(int error, const char* desctiption) 
	{
		PANDORA_CORE_ERROR("GLFW Error. {0} : {1}", error, desctiption);
	}


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
			glfwSetErrorCallback(GLFWErrorCallback);

			s_IsGLFWInitialized = true;
		}

		m_Window = glfwCreateWindow((int)m_Data.Width, (int)m_Data.Heigth, m_Data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		
		SetVSyncEnabled(true);
		SetGLFWCallbacks();
	}

	void WindowWin32::Terminate()
	{
		glfwDestroyWindow(m_Window);
	}

	void WindowWin32::SetGLFWCallbacks()
	{
		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
		{
			WindowDataWin32& data = *(WindowDataWin32*)glfwGetWindowUserPointer(window);
			data.Width = width;
			data.Heigth = height;

			WindowResizeEvent event(width, height);
			data.EventCallback(event);
		});

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
		{
			WindowDataWin32& data = *(WindowDataWin32*)glfwGetWindowUserPointer(window);
			WindowCloseEvent event;
			data.EventCallback(event);
		});

		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int modes)
		{
			WindowDataWin32& data = *(WindowDataWin32*)glfwGetWindowUserPointer(window);
			switch (action)
			{
				case GLFW_PRESS:
				{
					KeyPressedEvent event(key, false);
					data.EventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleasedEvent event(key);
					data.EventCallback(event);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPressedEvent event(key, true);
					data.EventCallback(event);
					break;
				}
			}
		});

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int modes)
		{
			WindowDataWin32& data = *(WindowDataWin32*)glfwGetWindowUserPointer(window);
			switch (action)
			{
				case GLFW_PRESS:
				{
					MouseButtonPressedEvent event(button);
					data.EventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent event(button);
					data.EventCallback(event);
					break;
				}
			}
		});

		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double offsetX, double offsetY)
		{
			WindowDataWin32& data = *(WindowDataWin32*)glfwGetWindowUserPointer(window);
			MouseScrolledEvent event((float)offsetX, (float)offsetY);
			data.EventCallback(event);
		});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double positionX, double positionY)
		{
			WindowDataWin32& data = *(WindowDataWin32*)glfwGetWindowUserPointer(window);
			MouseMovedEvent event((float)positionX, (float)positionY);
			data.EventCallback(event);
		});
	}

}