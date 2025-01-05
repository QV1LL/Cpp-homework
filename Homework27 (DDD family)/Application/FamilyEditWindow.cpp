#include <Windows.h>
#include <iostream>

#include "json.hpp"
#include "Date.h"
#include "Name.h"
#include "PhoneNumber.h"
#include "Address.h"
#include "Parent.h"
#include "Family.h"

#include "FamilyEditWindow.h"

using namespace Project;

void Project::FamilyEditWindow::InitializeComponent(void)
{
    this->familyName = (gcnew System::Windows::Forms::TextBox());
    this->parentsPanel = (gcnew System::Windows::Forms::Panel());
    this->motherLabel = (gcnew System::Windows::Forms::Label());
    this->fatherLabel = (gcnew System::Windows::Forms::Label());
    this->editMotherButton = (gcnew System::Windows::Forms::Button());
    this->editFatherButton = (gcnew System::Windows::Forms::Button());
    this->parentsPanel->SuspendLayout();
    this->SuspendLayout();
    // 
    // familyName
    // 
    this->familyName->BackColor = System::Drawing::SystemColors::Window;
    this->familyName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->familyName->ForeColor = System::Drawing::SystemColors::WindowText;
    this->familyName->Location = System::Drawing::Point(12, 12);
    this->familyName->Name = L"familyName";
    this->familyName->Size = System::Drawing::Size(340, 38);
    this->familyName->TabIndex = 0;
    this->familyName->Text = L"Family name";
    // 
    // panel1
    // 
    this->parentsPanel->BackColor = System::Drawing::SystemColors::ControlLightLight;
    this->parentsPanel->Controls->Add(this->editFatherButton);
    this->parentsPanel->Controls->Add(this->editMotherButton);
    this->parentsPanel->Controls->Add(this->fatherLabel);
    this->parentsPanel->Controls->Add(this->motherLabel);
    this->parentsPanel->Location = System::Drawing::Point(14, 59);
    this->parentsPanel->Name = L"panel1";
    this->parentsPanel->Size = System::Drawing::Size(700, 84);
    this->parentsPanel->TabIndex = 1;
    // 
    // MotherLabel
    // 
    this->motherLabel->AutoSize = true;
    this->motherLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->motherLabel->Location = System::Drawing::Point(128, 0);
    this->motherLabel->Name = L"MotherLabel";
    this->motherLabel->Size = System::Drawing::Size(79, 25);
    this->motherLabel->TabIndex = 0;
    this->motherLabel->Text = L"Mother";
    // 
    // FatherLabel
    // 
    this->fatherLabel->AutoSize = true;
    this->fatherLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->fatherLabel->Location = System::Drawing::Point(475, 0);
    this->fatherLabel->Name = L"FatherLabel";
    this->fatherLabel->Size = System::Drawing::Size(74, 25);
    this->fatherLabel->TabIndex = 1;
    this->fatherLabel->Text = L"Father";
    // 
    // EditMotherButton
    // 
    this->editMotherButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->editMotherButton->Location = System::Drawing::Point(79, 47);
    this->editMotherButton->Name = L"EditMotherButton";
    this->editMotherButton->Size = System::Drawing::Size(180, 36);
    this->editMotherButton->TabIndex = 2;
    this->editMotherButton->Text = L"Edit";
    this->editMotherButton->UseVisualStyleBackColor = true;
    this->editMotherButton->Cursor = System::Windows::Forms::Cursors::Hand;
    // 
    // EditFatherButton
    // 
    this->editFatherButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->editFatherButton->Location = System::Drawing::Point(422, 45);
    this->editFatherButton->Name = L"EditFatherButton";
    this->editFatherButton->Size = System::Drawing::Size(180, 36);
    this->editFatherButton->TabIndex = 3;
    this->editFatherButton->Text = L"Edit";
    this->editFatherButton->UseVisualStyleBackColor = true;
    this->editMotherButton->Cursor = System::Windows::Forms::Cursors::Hand;
    // 
    // FamilyEditWindow
    // 
    this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
    this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
    this->ClientSize = System::Drawing::Size(821, 554);
    this->Controls->Add(this->parentsPanel);
    this->Controls->Add(this->familyName);
    this->Cursor = System::Windows::Forms::Cursors::Default;
    this->Name = L"FamilyEditWindow";
    this->ShowIcon = false;
    this->Text = L"Family edit window";
    this->parentsPanel->ResumeLayout(false);
    this->parentsPanel->PerformLayout();
    this->ResumeLayout(false);
    this->PerformLayout();

}
