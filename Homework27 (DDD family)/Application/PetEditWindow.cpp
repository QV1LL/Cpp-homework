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

#include "PetEditWindow.h"

using namespace Project;

void Project::PetEditWindow::InitializeComponent(void)
{
    this->nameTextBox = (gcnew System::Windows::Forms::TextBox());
    this->day = (gcnew System::Windows::Forms::NumericUpDown());
    this->birthDateLabel = (gcnew System::Windows::Forms::Label());
    this->month = (gcnew System::Windows::Forms::NumericUpDown());
    this->year = (gcnew System::Windows::Forms::NumericUpDown());
    this->petTypeLabel = (gcnew System::Windows::Forms::Label());
    this->petTypeTextBox = (gcnew System::Windows::Forms::TextBox());
    this->weightLabel = (gcnew System::Windows::Forms::Label());
    this->weight = (gcnew System::Windows::Forms::TextBox());
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
        gcnew System::String(std::string(this->pet->getName()).c_str());
    this->nameTextBox->TextChanged +=
        gcnew System::EventHandler(this, &PetEditWindow::onTextChanged);
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
        gcnew System::String(std::to_string(this->pet->getBirthDate().getDay()).c_str());
    this->day->TextChanged +=
        gcnew System::EventHandler(this, &PetEditWindow::onTextChanged);
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
        gcnew System::String(std::to_string(this->pet->getBirthDate().getMonth()).c_str());
    this->month->TextChanged +=
        gcnew System::EventHandler(this, &PetEditWindow::onTextChanged);
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
        gcnew System::String(std::to_string(this->pet->getBirthDate().getYear()).c_str());
    this->year->TextChanged +=
        gcnew System::EventHandler(this, &PetEditWindow::onTextChanged);
    // 
    // petTypeLabel
    // 
    this->petTypeLabel->AutoSize = true;
    this->petTypeLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->petTypeLabel->Location = System::Drawing::Point(12, 130);
    this->petTypeLabel->Name = L"petTypeLabel";
    this->petTypeLabel->Size = System::Drawing::Size(89, 25);
    this->petTypeLabel->TabIndex = 7;
    this->petTypeLabel->Text = L"Pet type";
    // 
    // petTypeTextBox
    // 
    this->petTypeTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->petTypeTextBox->Location = System::Drawing::Point(12, 158);
    this->petTypeTextBox->Name = L"petTypeTextBox";
    this->petTypeTextBox->Size = System::Drawing::Size(342, 26);
    this->petTypeTextBox->TabIndex = 8;
    this->petTypeTextBox->Text =
        gcnew System::String(Project::stringPetTypes[int(this->pet->getPetType())].c_str());
    this->petTypeTextBox->TextChanged +=
        gcnew System::EventHandler(this, &PetEditWindow::onTextChanged);
    // 
    // weightLabel
    // 
    this->weightLabel->AutoSize = true;
    this->weightLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->weightLabel->Location = System::Drawing::Point(12, 212);
    this->weightLabel->Name = L"weightLabel";
    this->weightLabel->Size = System::Drawing::Size(124, 25);
    this->weightLabel->TabIndex = 9;
    this->weightLabel->Text = L"Weight";
    // 
    // weight
    // 
    this->weight->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->weight->Location = System::Drawing::Point(12, 240);
    this->weight->Name = L"weight";
    this->weight->Size = System::Drawing::Size(95, 26);
    this->weight->TabIndex = 3;
    this->weight->Text =
        gcnew System::String(std::to_string(this->pet->getWeight()).c_str());
    this->weight->TextChanged +=
        gcnew System::EventHandler(this, &PetEditWindow::onTextChanged);
    // 
    // PetEditWindow
    // 
    this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
    this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
    this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
    this->ClientSize = System::Drawing::Size(361, 494);
    this->Controls->Add(this->weightLabel);
    this->Controls->Add(this->weight);
    this->Controls->Add(this->petTypeTextBox);
    this->Controls->Add(this->petTypeLabel);
    this->Controls->Add(this->year);
    this->Controls->Add(this->month);
    this->Controls->Add(this->birthDateLabel);
    this->Controls->Add(this->day);
    this->Controls->Add(this->nameTextBox);
    this->Name = L"PetEditWindow";
    this->Text = L"Family member edit window";
    (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->day))->EndInit();
    (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->month))->EndInit();
    (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->year))->EndInit();
    this->ResumeLayout(false);
    this->PerformLayout();
}

System::Void Project::PetEditWindow::onTextChanged(System::Object^ sender, System::EventArgs^ e)
{
    Control^ control = safe_cast<Control^>(sender);
    msclr::interop::marshal_context context;

    try
    {
        if (control == this->nameTextBox)
            this->pet->setName(context.marshal_as<std::string>(control->Text));

        else if (control == this->day)
            this->pet->setBirthDate(Date{
                uint16_t(std::stoi(context.marshal_as<std::string>(control->Text))),
                this->pet->getBirthDate().getMonth(),
                this->pet->getBirthDate().getYear()
                });

        else if (control == this->month)
            this->pet->setBirthDate(Date{
                this->pet->getBirthDate().getDay(),
                uint16_t(std::stoi(context.marshal_as<std::string>(control->Text))),
                this->pet->getBirthDate().getYear()
                });

        else if (control == this->year)
            this->pet->setBirthDate(Date{
                this->pet->getBirthDate().getDay(),
                this->pet->getBirthDate().getMonth(),
                uint16_t(std::stoi(context.marshal_as<std::string>(control->Text)))
                });

        else if (control == this->petTypeTextBox)
        {
            for (int i = 0; i < 4; i++)
                if (stringPetTypes[i] == context.marshal_as<std::string>(control->Text))
                    this->pet->setPetType(Project::PetType(i));
        }

        else if (control == this->weight)
            this->pet->setWeight(
                std::stof(context.marshal_as<std::string>(control->Text))
            );
    }
    catch (System::Exception^ e)
    {

    }
}