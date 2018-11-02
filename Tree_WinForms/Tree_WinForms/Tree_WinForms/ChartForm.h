#pragma once

#include "Forest.h"
#include <time.h>
#include <fstream>

namespace TreeWinForms {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace Forest_nspace;

	int n = 0;
	vector<double> x;
	vector<double> y;

	Forest Taiga = Forest();

	public ref class ChartForm : public System::Windows::Forms::Form {
	public: ChartForm(void)	{ 
			InitializeComponent(); 
			srand((unsigned int)time(NULL));
		}
	protected: ~ChartForm() { if (components) { delete components; } }
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  Chart;
	private: System::Windows::Forms::SplitContainer^  splitContainer;
	private: System::Windows::Forms::MenuStrip^  menuStrip;
	private: System::Windows::Forms::ToolStripMenuItem^  файлToolStripMenuItem;
	private: System::Windows::Forms::Button^  Отрисовать;
	private: System::Windows::Forms::TextBox^  Пригодность;
	private: System::Windows::Forms::Button^  Исходная;
	private: System::Windows::Forms::StatusStrip^  statusStrip2;
	private: System::Windows::Forms::Button^  Скрещивание;
	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	private: System::Windows::Forms::ToolStripStatusLabel^  Формула;
	private: System::Windows::Forms::ToolStripStatusLabel^  Формула2;
	private: System::Windows::Forms::Button^  Создать;
	private: System::Windows::Forms::Button^  button1;
	private: System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->Chart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->splitContainer = (gcnew System::Windows::Forms::SplitContainer());
			this->Создать = (gcnew System::Windows::Forms::Button());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->Формула = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->Скрещивание = (gcnew System::Windows::Forms::Button());
			this->statusStrip2 = (gcnew System::Windows::Forms::StatusStrip());
			this->Формула2 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->Исходная = (gcnew System::Windows::Forms::Button());
			this->Пригодность = (gcnew System::Windows::Forms::TextBox());
			this->Отрисовать = (gcnew System::Windows::Forms::Button());
			this->menuStrip = (gcnew System::Windows::Forms::MenuStrip());
			this->файлToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Chart))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer))->BeginInit();
			this->splitContainer->Panel1->SuspendLayout();
			this->splitContainer->Panel2->SuspendLayout();
			this->splitContainer->SuspendLayout();
			this->statusStrip1->SuspendLayout();
			this->statusStrip2->SuspendLayout();
			this->menuStrip->SuspendLayout();
			this->SuspendLayout();
			// 
			// Chart
			// 
			chartArea1->Name = L"ChartArea1";
			this->Chart->ChartAreas->Add(chartArea1);
			this->Chart->Dock = System::Windows::Forms::DockStyle::Fill;
			legend1->Name = L"Legend1";
			this->Chart->Legends->Add(legend1);
			this->Chart->Location = System::Drawing::Point(0, 0);
			this->Chart->Name = L"Chart";
			series1->BorderWidth = 5;
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series1->Color = System::Drawing::Color::Black;
			series1->EmptyPointStyle->Color = System::Drawing::Color::White;
			series1->Legend = L"Legend1";
			series1->MarkerColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			series1->MarkerSize = 50;
			series1->Name = L"Исходная";
			series1->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Double;
			series1->YValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Double;
			series2->BorderWidth = 5;
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series2->Color = System::Drawing::Color::Red;
			series2->Legend = L"Legend1";
			series2->Name = L"Дерево1";
			series3->BorderWidth = 5;
			series3->ChartArea = L"ChartArea1";
			series3->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series3->Color = System::Drawing::Color::Blue;
			series3->Legend = L"Legend1";
			series3->Name = L"Дерево2";
			this->Chart->Series->Add(series1);
			this->Chart->Series->Add(series2);
			this->Chart->Series->Add(series3);
			this->Chart->Size = System::Drawing::Size(885, 683);
			this->Chart->TabIndex = 0;
			this->Chart->Text = L"Chart";
			// 
			// splitContainer
			// 
			this->splitContainer->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->splitContainer->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer->Location = System::Drawing::Point(0, 24);
			this->splitContainer->Name = L"splitContainer";
			// 
			// splitContainer.Panel1
			// 
			this->splitContainer->Panel1->Controls->Add(this->Chart);
			// 
			// splitContainer.Panel2
			// 
			this->splitContainer->Panel2->Controls->Add(this->button1);
			this->splitContainer->Panel2->Controls->Add(this->Создать);
			this->splitContainer->Panel2->Controls->Add(this->statusStrip1);
			this->splitContainer->Panel2->Controls->Add(this->Скрещивание);
			this->splitContainer->Panel2->Controls->Add(this->statusStrip2);
			this->splitContainer->Panel2->Controls->Add(this->Исходная);
			this->splitContainer->Panel2->Controls->Add(this->Пригодность);
			this->splitContainer->Panel2->Controls->Add(this->Отрисовать);
			this->splitContainer->Size = System::Drawing::Size(1280, 687);
			this->splitContainer->SplitterDistance = 889;
			this->splitContainer->TabIndex = 1;
			// 
			// Создать
			// 
			this->Создать->Location = System::Drawing::Point(22, 48);
			this->Создать->Name = L"Создать";
			this->Создать->Size = System::Drawing::Size(129, 23);
			this->Создать->TabIndex = 7;
			this->Создать->Text = L"/roll";
			this->Создать->UseVisualStyleBackColor = true;
			this->Создать->Click += gcnew System::EventHandler(this, &ChartForm::Создать_Click);
			// 
			// statusStrip1
			// 
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->Формула });
			this->statusStrip1->Location = System::Drawing::Point(0, 639);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(383, 22);
			this->statusStrip1->SizingGrip = false;
			this->statusStrip1->TabIndex = 6;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// Формула
			// 
			this->Формула->Name = L"Формула";
			this->Формула->Size = System::Drawing::Size(58, 17);
			this->Формула->Text = L"Формула";
			// 
			// Скрещивание
			// 
			this->Скрещивание->Location = System::Drawing::Point(22, 106);
			this->Скрещивание->Name = L"Скрещивание";
			this->Скрещивание->Size = System::Drawing::Size(129, 23);
			this->Скрещивание->TabIndex = 5;
			this->Скрещивание->Text = L"Скрещивание";
			this->Скрещивание->UseVisualStyleBackColor = true;
			this->Скрещивание->Click += gcnew System::EventHandler(this, &ChartForm::Скрещивание_Click);
			// 
			// statusStrip2
			// 
			this->statusStrip2->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->Формула2 });
			this->statusStrip2->Location = System::Drawing::Point(0, 661);
			this->statusStrip2->Name = L"statusStrip2";
			this->statusStrip2->Size = System::Drawing::Size(383, 22);
			this->statusStrip2->SizingGrip = false;
			this->statusStrip2->TabIndex = 4;
			this->statusStrip2->Text = L"statusStrip2";
			this->statusStrip2->ItemClicked += gcnew System::Windows::Forms::ToolStripItemClickedEventHandler(this, &ChartForm::statusStrip2_ItemClicked);
			// 
			// Формула2
			// 
			this->Формула2->Name = L"Формула2";
			this->Формула2->Size = System::Drawing::Size(64, 17);
			this->Формула2->Text = L"Формула2";
			// 
			// Исходная
			// 
			this->Исходная->Location = System::Drawing::Point(22, 19);
			this->Исходная->Name = L"Исходная";
			this->Исходная->Size = System::Drawing::Size(129, 23);
			this->Исходная->TabIndex = 3;
			this->Исходная->Text = L"Рисовать исходную";
			this->Исходная->UseVisualStyleBackColor = true;
			this->Исходная->Click += gcnew System::EventHandler(this, &ChartForm::Исходная_Click);
			// 
			// Пригодность
			// 
			this->Пригодность->Location = System::Drawing::Point(22, 200);
			this->Пригодность->Name = L"Пригодность";
			this->Пригодность->Size = System::Drawing::Size(129, 20);
			this->Пригодность->TabIndex = 1;
			// 
			// Отрисовать
			// 
			this->Отрисовать->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Отрисовать->Location = System::Drawing::Point(22, 77);
			this->Отрисовать->Name = L"Отрисовать";
			this->Отрисовать->Size = System::Drawing::Size(129, 23);
			this->Отрисовать->TabIndex = 0;
			this->Отрисовать->Text = L"Отрисовать";
			this->Отрисовать->UseVisualStyleBackColor = true;
			this->Отрисовать->Click += gcnew System::EventHandler(this, &ChartForm::Отрисовать_Click);
			// 
			// menuStrip
			// 
			this->menuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->файлToolStripMenuItem });
			this->menuStrip->Location = System::Drawing::Point(0, 0);
			this->menuStrip->Name = L"menuStrip";
			this->menuStrip->Size = System::Drawing::Size(1280, 24);
			this->menuStrip->TabIndex = 2;
			this->menuStrip->Text = L"menuStrip";
			// 
			// файлToolStripMenuItem
			// 
			this->файлToolStripMenuItem->Name = L"файлToolStripMenuItem";
			this->файлToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->файлToolStripMenuItem->Text = L"Файл";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(22, 136);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(129, 23);
			this->button1->TabIndex = 8;
			this->button1->Text = L"Мутация";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ChartForm::button1_Click);
			// 
			// ChartForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1280, 711);
			this->Controls->Add(this->splitContainer);
			this->Controls->Add(this->menuStrip);
			this->MainMenuStrip = this->menuStrip;
			this->Name = L"ChartForm";
			this->Text = L"ChartForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Chart))->EndInit();
			this->splitContainer->Panel1->ResumeLayout(false);
			this->splitContainer->Panel2->ResumeLayout(false);
			this->splitContainer->Panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer))->EndInit();
			this->splitContainer->ResumeLayout(false);
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->statusStrip2->ResumeLayout(false);
			this->statusStrip2->PerformLayout();
			this->menuStrip->ResumeLayout(false);
			this->menuStrip->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	private: void Read_File(string file1, string file2) {
		ifstream fin;

		fin.open(file1);
		fin >> n;
		x.resize(n);
		for (int i = 0; i < n; i++) fin >> x[i];
		fin.close();

		fin.open(file2);
		fin >> n;
		y.resize(n);
		for (int i = 0; i < n; i++) fin >> y[i];
		fin.close();
	}
	private: System::Void Отрисовать_Click(System::Object^  sender, System::EventArgs^  e) {
		Формула->Text = "y = " + gcnew System::String(Taiga.Population[0].Print().c_str());
		Формула2->Text = "y = " + gcnew System::String(Taiga.Population[1].Print().c_str());

		Chart->Series["Дерево1"]->Points->Clear();
		Chart->Series["Дерево2"]->Points->Clear();
		for (int i = 0; i < 100; i++) {
			Chart->Series["Дерево1"]->Points->AddXY(x[i], Taiga.Population[0].GetY(x[i]));
			Chart->Series["Дерево2"]->Points->AddXY(x[i], Taiga.Population[1].GetY(x[i]));
		}
		//Taiga.Population[0].Fitness(n, x, y);
		//Пригодность->Text = Convert::ToString(Taiga.Population[0].GetFitness());		
	}
	private: System::Void Исходная_Click(System::Object^  sender, System::EventArgs^  e) {
		Read_File("res/sin/2x.txt", "res/sin/2y.txt");

		Chart->Series["Исходная"]->Points->Clear();
		for (int i = 0; i < n; i++) Chart->Series["Исходная"]->Points->AddXY(x[i], y[i]);
	}
	private: System::Void Скрещивание_Click(System::Object^  sender, System::EventArgs^  e) {
		vector<int> Order(Taiga.GetSize()*2);
		for (int i = 0; i < Taiga.GetSize(); i++) {
			int a = 0, b = 0;
			while (a == b) {
				a = rand() % Taiga.GetSize(); //10;
				b = rand() % Taiga.GetSize(); //10;
			}
			Order[i * 2] = a;
			Order[i * 2 + 1] = b;
		}
		Taiga.CrossOver(Order);
	}
	private: System::Void Создать_Click(System::Object^  sender, System::EventArgs^  e) {
		Taiga = Forest(2, 3, -10, 20);
	}
private: System::Void statusStrip2_ItemClicked(System::Object^  sender, System::Windows::Forms::ToolStripItemClickedEventArgs^  e) {
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	Taiga.TreeMutation(1, -10, 20);
}
};
}
