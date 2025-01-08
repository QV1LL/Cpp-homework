#include <Windows.h>
#include <iostream>
#include <msclr\marshal_cppstd.h>

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
    this->nameTextBox->TextChanged += 
        gcnew System::EventHandler(this, &FamilyMemberEditWindow::onTextChanged);
    // 
    // day
    // 
    this->day->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->day->Location = System::Drawing::Point(12, 84);
    this->day->Name = L"day";
    this->day->Size = System::Drawing::Size(95, 26);
    this->day->TabIndex = 1;
    this->day->Minimum = 1;
    this->day->Maximum = 31;
    this->day->Text =
        gcnew System::String(std::to_string(this->familyMember->getBirthDate().getDay()).c_str());
    this->day->TextChanged +=
        gcnew System::EventHandler(this, &FamilyMemberEditWindow::onTextChanged);
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
    this->month->Minimum = 1;
    this->month->Maximum = 12;
    this->month->Text = 
        gcnew System::String(std::to_string(this->familyMember->getBirthDate().getMonth()).c_str());
    this->month->TextChanged += 
        gcnew System::EventHandler(this, &FamilyMemberEditWindow::onTextChanged);
    // 
    // year
    // 
    this->year->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->year->Location = System::Drawing::Point(259, 84);
    this->year->Name = L"year";
    this->year->Size = System::Drawing::Size(95, 26);
    this->year->TabIndex = 4;
    this->year->Minimum = 1900;
    this->year->Maximum = Project::getCurrentYear();
    this->year->Text = 
        gcnew System::String(std::to_string(this->familyMember->getBirthDate().getYear()).c_str());
    this->year->TextChanged +=
        gcnew System::EventHandler(this, &FamilyMemberEditWindow::onTextChanged);
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
    this->phoneNumberTextBox->TextChanged +=
        gcnew System::EventHandler(this, &FamilyMemberEditWindow::onTextChanged);
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
    this->genderTextBox->Text = 
        gcnew System::String(Project::stringGenders[int(this->familyMember->getGender())].c_str());
    this->genderTextBox->TextChanged +=
        gcnew System::EventHandler(this, &FamilyMemberEditWindow::onTextChanged);
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
    this->nationalityTextBox->TextChanged +=
        gcnew System::EventHandler(this, &FamilyMemberEditWindow::onTextChanged);
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
        gcnew System::String(std::string(this->familyMember->getName().getLastName()).c_str());
    this->surnameTextBox->TextChanged += 
        gcnew System::EventHandler(this, &FamilyMemberEditWindow::onTextChanged);
    // 
    // FamilyMemberEditWindow
    // 
    this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
    this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
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

System::Void Project::FamilyMemberEditWindow::onTextChanged(System::Object^ sender, System::EventArgs^ e)
{
    Control^ control = safe_cast<Control^>(sender);
    msclr::interop::marshal_context context;

    try
    {
        if (control == this->nameTextBox)
            this->familyMember->setName({ context.marshal_as<std::string>(control->Text),
                this->familyMember->getName().getLastName() });

        else if (control == this->surnameTextBox)
            this->familyMember->setName({ this->familyMember->getName().getFirstName(),
                context.marshal_as<std::string>(control->Text) });

        else if (control == this->day)
            this->familyMember->setBirthDate(Date{
                uint16_t(std::stoi(context.marshal_as<std::string>(control->Text))),
                this->familyMember->getBirthDate().getMonth(),
                this->familyMember->getBirthDate().getYear()
                });

        else if (control == this->month)
            this->familyMember->setBirthDate(Date{
                this->familyMember->getBirthDate().getDay(),
                uint16_t(std::stoi(context.marshal_as<std::string>(control->Text))),
                this->familyMember->getBirthDate().getYear()
                });

        else if (control == this->year)
            this->familyMember->setBirthDate(Date{
                this->familyMember->getBirthDate().getDay(),
                this->familyMember->getBirthDate().getMonth(),
                uint16_t(std::stoi(context.marshal_as<std::string>(control->Text)))
                });

        else if (control == this->phoneNumberTextBox)
            this->familyMember->setPhoneNumber({
            context.marshal_as<std::string>(control->Text)
                });

        else if (control == this->genderTextBox)
        {
            for (int i = 0; i < 2; i++)
                if (stringGenders[i] == context.marshal_as<std::string>(control->Text))
                    this->familyMember->setGender(Project::Gender(i));
        }

        else if (control == this->nationalityTextBox)
            this->familyMember->setNationality(
                context.marshal_as<std::string>(control->Text)
            );
    }
    catch (System::Exception^ e)
    {

    }
}
