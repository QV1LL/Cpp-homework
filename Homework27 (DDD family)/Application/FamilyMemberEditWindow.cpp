#include <Windows.h>
#include <iostream>

#include "json.hpp"
#include "Date.h"
#include "Name.h"
#include "PhoneNumber.h"
#include "Address.h"
#include "Parent.h"
#include "Family.h"
#include "Child.h"
#include "Pet.h"

#include "FamilyMemberEditWindow.h"

using namespace Project;

void Project::FamilyMemberEditWindow::InitializeComponent(void)
{
    this->nameTextBox = (gcnew System::Windows::Forms::TextBox());
    this->day = (gcnew System::Windows::Forms::NumericUpDown());
    this->birthDateLabel = (gcnew System::Windows::Forms::Label());
    this->month = (gcnew System::Windows::Forms::NumericUpDown());
    this->year = (gcnew System::Windows::Forms::NumericUpDown());
    this->phoneNumberTextBox = (gcnew System::Windows::Forms::TextBox());
    this->phoneNumberLabel = (gcnew System::Windows::Forms::Label());
    this->genderLabel = (gcnew System::Windows::Forms::Label());
    this->genderTextBox = (gcnew System::Windows::Forms::TextBox());
    this->nationalityLabel = (gcnew System::Windows::Forms::Label());
    this->nationalityTextBox = (gcnew System::Windows::Forms::TextBox());
    this->surnameTextBox = (gcnew System::Windows::Forms::TextBox());
    (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->day))->BeginInit();
    (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->month))->BeginInit();
    (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->year))->BeginInit();
    this->SuspendLayout();
    // 
    // nameTextBox
    // 
    this->nameTextBox->BackColor = System::Drawing::SystemColors::Window;
    this->nameTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->nameTextBox->Location = System::Drawing::Point(12, 12);
    this->nameTextBox->Name = L"nameTextBox";
    this->nameTextBox->Size = System::Drawing::Size(164, 31);
    this->nameTextBox->TabIndex = 0;
    this->nameTextBox->Text = 
        gcnew System::String(std::string(this->familyMember->getName().getFirstName()).c_str());
    this->nameTextBox->TextChanged += gcnew System::EventHandler(this, &FamilyMemberEditWindow::name_TextChanged);
    // 
    // day
    // 
    this->day->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->day->Location = System::Drawing::Point(12, 84);
    this->day->Name = L"day";
    this->day->Size = System::Drawing::Size(95, 26);
    this->day->TabIndex = 1;
    this->day->Text =
        gcnew System::String(std::to_string(this->familyMember->getBirthDate().getDay()).c_str());
    // 
    // birthDateLabel
    // 
    this->birthDateLabel->AutoSize = true;
    this->birthDateLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->birthDateLabel->Location = System::Drawing::Point(12, 56);
    this->birthDateLabel->Name = L"birthDateLabel";
    this->birthDateLabel->Size = System::Drawing::Size(114, 25);
    this->birthDateLabel->TabIndex = 2;
    this->birthDateLabel->Text = L"Birth date";
    // 
    // month
    // 
    this->month->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->month->Location = System::Drawing::Point(136, 84);
    this->month->Name = L"month";
    this->month->Size = System::Drawing::Size(95, 26);
    this->month->TabIndex = 3;
    this->month->Text = 
        gcnew System::String(std::to_string(this->familyMember->getBirthDate().getMonth()).c_str());
    // 
    // year
    // 
    this->year->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->year->Location = System::Drawing::Point(259, 84);
    this->year->Name = L"year";
    this->year->Size = System::Drawing::Size(95, 26);
    this->year->TabIndex = 4;
    this->year->Text = 
        gcnew System::String(std::to_string(this->familyMember->getBirthDate().getYear()).c_str());
    // 
    // phoneNumberTextBox
    // 
    this->phoneNumberTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->phoneNumberTextBox->Location = System::Drawing::Point(7, 158);
    this->phoneNumberTextBox->Name = L"phoneNumberTextBox";
    this->phoneNumberTextBox->Size = System::Drawing::Size(342, 26);
    this->phoneNumberTextBox->TabIndex = 5;
    this->phoneNumberTextBox->Text =
        gcnew System::String(std::string(this->familyMember->getPhoneNumber()).c_str());
    // 
    // phoneNumberLabel
    // 
    this->phoneNumberLabel->AutoSize = true;
    this->phoneNumberLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->phoneNumberLabel->Location = System::Drawing::Point(12, 130);
    this->phoneNumberLabel->Name = L"phoneNumberLabel";
    this->phoneNumberLabel->Size = System::Drawing::Size(164, 25);
    this->phoneNumberLabel->TabIndex = 6;
    this->phoneNumberLabel->Text = L"Phone number";
    // 
    // genderLabel
    // 
    this->genderLabel->AutoSize = true;
    this->genderLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->genderLabel->Location = System::Drawing::Point(12, 212);
    this->genderLabel->Name = L"genderLabel";
    this->genderLabel->Size = System::Drawing::Size(89, 25);
    this->genderLabel->TabIndex = 7;
    this->genderLabel->Text = L"Gender";
    // 
    // genderTextBox
    // 
    this->genderTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->genderTextBox->Location = System::Drawing::Point(12, 240);
    this->genderTextBox->Name = L"genderTextBox";
    this->genderTextBox->Size = System::Drawing::Size(342, 26);
    this->genderTextBox->TabIndex = 8;
    // 
    // nationalityLabel
    // 
    this->nationalityLabel->AutoSize = true;
    this->nationalityLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->nationalityLabel->Location = System::Drawing::Point(12, 299);
    this->nationalityLabel->Name = L"nationalityLabel";
    this->nationalityLabel->Size = System::Drawing::Size(124, 25);
    this->nationalityLabel->TabIndex = 9;
    this->nationalityLabel->Text = L"Nationality";
    // 
    // nationalityTextBox
    // 
    this->nationalityTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->nationalityTextBox->Location = System::Drawing::Point(12, 327);
    this->nationalityTextBox->Name = L"nationalityTextBox";
    this->nationalityTextBox->Size = System::Drawing::Size(342, 26);
    this->nationalityTextBox->TabIndex = 10;
    this->nationalityTextBox->Text =
        gcnew System::String(std::string(this->familyMember->getNationality()).c_str());
    // 
    // surnameTextBox
    // 
    this->surnameTextBox->BackColor = System::Drawing::SystemColors::Window;
    this->surnameTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->surnameTextBox->Location = System::Drawing::Point(190, 12);
    this->surnameTextBox->Name = L"surnameTextBox";
    this->surnameTextBox->Size = System::Drawing::Size(164, 31);
    this->surnameTextBox->TabIndex = 11;
    this->surnameTextBox->Text = 
        gcnew System::String(std::string(this->familyMember->getName().getLastName()).c_str());;
    // 
    // FamilyMemberEditWindow
    // 
    this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
    this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
    this->ClientSize = System::Drawing::Size(361, 494);
    this->Controls->Add(this->surnameTextBox);
    this->Controls->Add(this->nationalityTextBox);
    this->Controls->Add(this->nationalityLabel);
    this->Controls->Add(this->genderTextBox);
    this->Controls->Add(this->genderLabel);
    this->Controls->Add(this->phoneNumberLabel);
    this->Controls->Add(this->phoneNumberTextBox);
    this->Controls->Add(this->year);
    this->Controls->Add(this->month);
    this->Controls->Add(this->birthDateLabel);
    this->Controls->Add(this->day);
    this->Controls->Add(this->nameTextBox);
    this->Name = L"FamilyMemberEditWindow";
    this->Text = L"Family member edit window";
    (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->day))->EndInit();
    (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->month))->EndInit();
    (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->year))->EndInit();
    this->ResumeLayout(false);
    this->PerformLayout();

}
