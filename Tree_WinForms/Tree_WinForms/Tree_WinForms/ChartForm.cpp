#include "ChartForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void Main(array<String^>^ arg) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	TreeWinForms::ChartForm form; //WinFormsTest - имя вашего проекта
	Application::Run(%form);
}