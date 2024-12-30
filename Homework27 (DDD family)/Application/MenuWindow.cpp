#include "MenuWindow.h"
#include <Windows.h>

using namespace Project;

[STAThreadAttribute]
int WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
	MenuWindow^ menuWindow = gcnew MenuWindow();
    Application::Run(menuWindow);

    return 0;
}

void Project::MenuWindow::InitializeComponent(void)
{
    this->label1 = (gcnew System::Windows::Forms::Label());
    this->button1 = (gcnew System::Windows::Forms::Button());
    this->SuspendLayout();
    // 
    // label1
    // 
    this->label1->AutoSize = true;
    this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->label1->Location = System::Drawing::Point(12, 9);
    this->label1->Name = L"label1";
    this->label1->Size = System::Drawing::Size(440, 31);
    this->label1->TabIndex = 0;
    this->label1->Text = L"Choose family or create new one";
    this->label1->Click += gcnew System::EventHandler(this, &MenuWindow::label1_Click);
    // 
    // button1
    // 
    this->button1->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
    this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->button1->ForeColor = System::Drawing::Color::Snow;
    this->button1->Location = System::Drawing::Point(565, 9);
    this->button1->Name = L"button1";
    this->button1->Size = System::Drawing::Size(223, 30);
    this->button1->TabIndex = 1;
    this->button1->Text = L"Add";
    this->button1->UseVisualStyleBackColor = false;
    // 
    // MenuWindow
    // 
    this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
    this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
    this->ClientSize = System::Drawing::Size(800, 500);
    this->Controls->Add(this->button1);
    this->Controls->Add(this->label1);
    this->Cursor = System::Windows::Forms::Cursors::Arrow;
    this->Name = L"MenuWindow";
    this->ShowIcon = false;
    this->Text = L"Family simulator 1.0 beta";
    this->Load += gcnew System::EventHandler(this, &MenuWindow::MenuWindow_Load);
    this->ResumeLayout(false);
    this->PerformLayout();

}
