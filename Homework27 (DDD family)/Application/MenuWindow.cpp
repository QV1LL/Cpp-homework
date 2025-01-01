#include "MenuWindow.h"
#include <Windows.h>
#include <iostream>

#include "Date.h"
#include "Name.h"
#include "PhoneNumber.h"
#include "Address.h"
#include "Parent.h"

using namespace Project;

[STAThreadAttribute]
int main(HINSTANCE, HINSTANCE, LPSTR, int) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
	MenuWindow^ menuWindow = gcnew MenuWindow();
    Application::Run(menuWindow);

    return 0;
}

void Project::MenuWindow::InitializeComponent(void)
{
    this->label1 = (gcnew System::Windows::Forms::Label());
    this->addFamilyButton = (gcnew System::Windows::Forms::Button());
    this->panel = (gcnew System::Windows::Forms::Panel());
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
    // 
    // addFamilyButton
    // 
    this->addFamilyButton->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
    this->addFamilyButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->addFamilyButton->ForeColor = System::Drawing::Color::Snow;
    this->addFamilyButton->Location = System::Drawing::Point(565, 9);
    this->addFamilyButton->Name = L"addFamilyButton";
    this->addFamilyButton->Size = System::Drawing::Size(223, 30);
    this->addFamilyButton->TabIndex = 1;
    this->addFamilyButton->Text = L"Add";
    this->addFamilyButton->UseVisualStyleBackColor = false;
    this->addFamilyButton->Click += gcnew System::EventHandler(this, &MenuWindow::AddFamilyButton_Click);
    // 
    // panel
    // 
    this->panel->Location = System::Drawing::Point(18, 62);
    this->panel->Name = L"panel";
    this->panel->Size = System::Drawing::Size(770, 426);
    this->panel->TabIndex = 2;
    // 
    // MenuWindow
    // 
    this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
    this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
    this->ClientSize = System::Drawing::Size(800, 500);
    this->Controls->Add(this->panel);
    this->Controls->Add(this->addFamilyButton);
    this->Controls->Add(this->label1);
    this->Cursor = System::Windows::Forms::Cursors::Arrow;
    this->Name = L"MenuWindow";
    this->ShowIcon = false;
    this->Text = L"Family simulator 1.0 beta";
    this->Load += gcnew System::EventHandler(this, &MenuWindow::MenuWindow_Load);
    this->ResumeLayout(false);
    this->PerformLayout();

}

void Project::MenuWindow::AddFamily(Panel^ panel)
{
    Panel^ newFamilyPanel = gcnew Panel();
    newFamilyPanel->Location = System::Drawing::Point(0, 0 + panel->Controls->Count * 48);
    newFamilyPanel->Size = System::Drawing::Size(770, 48);
    newFamilyPanel->TabIndex = 2;

    // 
    // Family name
    // 
    Label^ familyName = gcnew Label();
    familyName->AutoSize = true;
    familyName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    familyName->Location = System::Drawing::Point(3, 0);
    familyName->Name = L"familyName";
    familyName->Size = System::Drawing::Size(51, 20);
    familyName->TabIndex = 0;
    familyName->Text = L"Family";
    // 
    // Open button
    // 
    Button^ openButton = gcnew Button();
    openButton->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
    openButton->ForeColor = System::Drawing::SystemColors::Control;
    openButton->Location = System::Drawing::Point(470, 0);
    openButton->Name = L"openButton";
    openButton->Size = System::Drawing::Size(147, 20);
    openButton->TabIndex = 1;
    openButton->Text = L"Open";
    openButton->UseVisualStyleBackColor = false;
    // 
    // Delete button
    // 
    Button^ deleteButton = gcnew Button();
    deleteButton->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
    deleteButton->ForeColor = System::Drawing::SystemColors::Control;
    deleteButton->Location = System::Drawing::Point(623, 0);
    deleteButton->Name = L"deleteButton";
    deleteButton->Size = System::Drawing::Size(147, 20);
    deleteButton->TabIndex = 2;
    deleteButton->Text = L"Delete";
    deleteButton->UseVisualStyleBackColor = false;
    deleteButton->Click += gcnew System::EventHandler(this, &MenuWindow::RemoveButtonClick);

    newFamilyPanel->Controls->Add(familyName);
    newFamilyPanel->Controls->Add(openButton);
    newFamilyPanel->Controls->Add(deleteButton);

    panel->Controls->Add(newFamilyPanel);
}

System::Void Project::MenuWindow::AddFamilyButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->AddFamily(this->panel);
}

System::Void Project::MenuWindow::RemoveButtonClick(System::Object^ sender, System::EventArgs^ e)
{
    this->panel->Controls->Remove(safe_cast<Button^>(sender)->Parent);
}
