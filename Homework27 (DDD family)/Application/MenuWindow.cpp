#include <Windows.h>
#include <iostream>
#include <vector>
#include <thread>

#include "json.hpp"
#include "Date.h"
#include "Name.h"
#include "json.hpp"
#include "Date.h"
#include "Name.h"
#include "PhoneNumber.h"
#include "Address.h"
#include "Parent.h"
#include "Family.h"
#include "Child.h"
#include "Pet.h"
#include "DataLoader.h"
#include "DataSaver.h"

#include "MenuWindow.h"
#include "FamilyEditWindow.h"

#define FAMILY_PANEL_SIZE 48

using namespace Project;

void fixLayoutAfterDelete(Panel^ panel, int panelSize, int deleteId);

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
    this->families = new std::vector<Family>();
    this->saveFolder = new std::string("savings");

    this->label1 = (gcnew System::Windows::Forms::Label());
    this->addFamilyButton = (gcnew System::Windows::Forms::Button());
    this->familyPanel = (gcnew System::Windows::Forms::Panel());

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
    this->addFamilyButton->Cursor = System::Windows::Forms::Cursors::Hand;
    this->addFamilyButton->Click += gcnew System::EventHandler(this, &MenuWindow::AddFamilyButton_Click);
    // 
    // panel
    // 
    this->familyPanel->Location = System::Drawing::Point(18, 62);
    this->familyPanel->Name = L"panel";
    this->familyPanel->Size = System::Drawing::Size(770, 426);
    this->familyPanel->TabIndex = 2;
    // 
    // MenuWindow
    // 
    this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
    this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
    this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
    this->ClientSize = System::Drawing::Size(800, 500);
    this->Controls->Add(this->familyPanel);
    this->Controls->Add(this->addFamilyButton);
    this->Controls->Add(this->label1);
    this->Cursor = System::Windows::Forms::Cursors::Arrow;
    this->Name = L"MenuWindow";
    this->ShowIcon = false;
    this->Text = L"Family simulator 1.0 beta";
    this->Load += gcnew System::EventHandler(this, &MenuWindow::MenuWindow_Load);
    this->ResumeLayout(false);
    this->PerformLayout();

    try
    {
        std::vector<json> serializedObjects = DataLoader::getInstance(*this->saveFolder)->load();

        for (const json& serializedObject : serializedObjects)
            AddFamily(this->familyPanel, serializedObject);
    }
    catch (std::invalid_argument e)
    {

    }
}

void Project::MenuWindow::AddFamily(Panel^ panel, const json& serializedObject)
{

    Panel^ newFamilyPanel = gcnew Panel();
    newFamilyPanel->Location = System::Drawing::Point(0, 0 + panel->Controls->Count * FAMILY_PANEL_SIZE);
    newFamilyPanel->Size = System::Drawing::Size(770, FAMILY_PANEL_SIZE);
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
    openButton->Cursor = System::Windows::Forms::Cursors::Hand;
    openButton->Click += gcnew System::EventHandler(this, &MenuWindow::EditButtonClick);
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
    deleteButton->Cursor = System::Windows::Forms::Cursors::Hand;
    deleteButton->Click += gcnew System::EventHandler(this, &MenuWindow::RemoveButtonClick);

    newFamilyPanel->Controls->Add(familyName);
    newFamilyPanel->Controls->Add(openButton);
    newFamilyPanel->Controls->Add(deleteButton);

    panel->Controls->Add(newFamilyPanel);

    if (!serializedObject.empty())
    {
        this->families->push_back(Family(serializedObject));
        familyName->Text = 
            gcnew System::String(serializedObject.at("family_name").get<std::string>().c_str());
    }

    else {
        this->families->push_back(Family(
            Project::Parent(
                Project::Name("Name", "Surname"),
                Project::Date(1, 1, 1999),
                Project::PhoneNumber(std::string("missing")),
                Project::Gender::MALE
            ),
            Project::Parent(
                Project::Name("Name", "Surname"),
                Project::Date(1, 1, 1999),
                Project::PhoneNumber(std::string("missing")),
                Project::Gender::FEMALE
            ),
            "Family"
        ));
    }
}

System::Void Project::MenuWindow::AddFamilyButton_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->AddFamily(this->familyPanel, json());
}

System::Void Project::MenuWindow::RemoveButtonClick(System::Object^ sender, System::EventArgs^ e)
{
    Control^ layoutToDelete = safe_cast<Button^>(sender)->Parent;

    int layoutToDeleteId = this->familyPanel->Controls->GetChildIndex(layoutToDelete);
    this->familyPanel->Controls->Remove(layoutToDelete);
    this->families->erase(this->families->begin() + layoutToDeleteId);

    fixLayoutAfterDelete(familyPanel, FAMILY_PANEL_SIZE, layoutToDeleteId);
}

void invokeEditWindow(Family& family)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    FamilyEditWindow^ familyEditWindow = gcnew FamilyEditWindow(family);
    Application::Run(familyEditWindow);
}

System::Void Project::MenuWindow::EditButtonClick(System::Object^ sender, System::EventArgs^ e)
{
    Control^ targetLayout = safe_cast<Button^>(sender)->Parent;
    int targetLayoutId = this->familyPanel->Controls->GetChildIndex(targetLayout);

    Family& targetFamily = this->families->at(targetLayoutId);

    std::thread familyEditWindowProcess(invokeEditWindow, std::ref(targetFamily));
    familyEditWindowProcess.join();

    Label^ labelToUpdate = safe_cast<Label^>(targetLayout->Controls["familyName"]);
    labelToUpdate->Text = 
        gcnew String(std::string(this->families->at(targetLayoutId).getName()).c_str());
}
