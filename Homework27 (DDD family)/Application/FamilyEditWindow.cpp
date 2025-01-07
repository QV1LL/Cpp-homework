#include <Windows.h>
#include <iostream>
#include <vector>
#include <string>
#include <thread>
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

#include "FamilyEditWindow.h"
#include "FamilyMemberEditWindow.h"

#define PANEL_SIZE 76

using namespace Project;

void fixLayoutAfterDelete(Panel^ panel, int panelSize, int deleteId)
{
    for (int i = deleteId; i < panel->Controls->Count; i++) {
        panel->Controls[i]->Location = Point(
            panel->Controls[i]->Location.X,
            panel->Controls[i]->Location.Y - panelSize
        );
    }
}

void Project::FamilyEditWindow::InitializeComponent(void)
{
    this->familyName = (gcnew System::Windows::Forms::TextBox());
    this->parentsPanel = (gcnew System::Windows::Forms::Panel());
    this->editFatherButton = (gcnew System::Windows::Forms::Button());
    this->editMotherButton = (gcnew System::Windows::Forms::Button());
    this->fatherLabel = (gcnew System::Windows::Forms::Label());
    this->motherLabel = (gcnew System::Windows::Forms::Label());
    this->childrenLabel = (gcnew System::Windows::Forms::Label());
    this->petsLabel = (gcnew System::Windows::Forms::Label());
    this->childrenPanel = (gcnew System::Windows::Forms::Panel());
    this->petsPanel = (gcnew System::Windows::Forms::Panel());
    this->addChildButton = (gcnew System::Windows::Forms::Button());
    this->addPetButton = (gcnew System::Windows::Forms::Button());
    this->parentsPanel->SuspendLayout();
    this->SuspendLayout();
    // 
    // familyName
    // 
    this->familyName->BackColor = System::Drawing::SystemColors::Window;
    this->familyName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->familyName->ForeColor = System::Drawing::SystemColors::WindowText;
    this->familyName->Location = System::Drawing::Point(194, 12);
    this->familyName->Name = L"familyName";
    this->familyName->Size = System::Drawing::Size(340, 38);
    this->familyName->TabIndex = 0;
    this->familyName->Text = 
        gcnew System::String(std::string(this->family.getName()).c_str());
    this->familyName->TextChanged += gcnew EventHandler(this, &FamilyEditWindow::onFamilyNameTextChanged);
    // 
    // parentsPanel
    // 
    this->parentsPanel->BackColor = System::Drawing::SystemColors::ControlLightLight;
    this->parentsPanel->Controls->Add(this->editFatherButton);
    this->parentsPanel->Controls->Add(this->editMotherButton);
    this->parentsPanel->Controls->Add(this->fatherLabel);
    this->parentsPanel->Controls->Add(this->motherLabel);
    this->parentsPanel->Location = System::Drawing::Point(14, 59);
    this->parentsPanel->Name = L"parentsPanel";
    this->parentsPanel->Size = System::Drawing::Size(700, 84);
    this->parentsPanel->TabIndex = 1;
    // 
    // editFatherButton
    // 
    this->editFatherButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->editFatherButton->Location = System::Drawing::Point(436, 45);
    this->editFatherButton->Name = L"editFatherButton";
    this->editFatherButton->Size = System::Drawing::Size(180, 36);
    this->editFatherButton->TabIndex = 3;
    this->editFatherButton->Text = L"Edit";
    this->editFatherButton->UseVisualStyleBackColor = true;
    this->editFatherButton->Click += gcnew System::EventHandler(this, &FamilyEditWindow::onFamilyMemberEditButtonClick);
    // 
    // editMotherButton
    // 
    this->editMotherButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->editMotherButton->Location = System::Drawing::Point(79, 47);
    this->editMotherButton->Name = L"editMotherButton";
    this->editMotherButton->Size = System::Drawing::Size(180, 36);
    this->editMotherButton->TabIndex = 2;
    this->editMotherButton->Text = L"Edit";
    this->editMotherButton->UseVisualStyleBackColor = true;
    this->editMotherButton->Click += gcnew System::EventHandler(this, &FamilyEditWindow::onFamilyMemberEditButtonClick);
    // 
    // fatherLabel
    // 
    this->fatherLabel->AutoSize = true;
    this->fatherLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->fatherLabel->Location = System::Drawing::Point(486, 0);
    this->fatherLabel->Name = L"fatherLabel";
    this->fatherLabel->Size = System::Drawing::Size(74, 25);
    this->fatherLabel->TabIndex = 1;
    this->fatherLabel->Text = L"Father";
    // 
    // motherLabel
    // 
    this->motherLabel->AutoSize = true;
    this->motherLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->motherLabel->Location = System::Drawing::Point(128, 0);
    this->motherLabel->Name = L"motherLabel";
    this->motherLabel->Size = System::Drawing::Size(79, 25);
    this->motherLabel->TabIndex = 0;
    this->motherLabel->Text = L"Mother";
    // 
    // childrenLabel
    // 
    this->childrenLabel->AutoSize = true;
    this->childrenLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->childrenLabel->Location = System::Drawing::Point(143, 162);
    this->childrenLabel->Name = L"childrenLabel";
    this->childrenLabel->Size = System::Drawing::Size(75, 20);
    this->childrenLabel->TabIndex = 2;
    this->childrenLabel->Text = L"Children";
    // 
    // petsLabel
    // 
    this->petsLabel->AutoSize = true;
    this->petsLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->petsLabel->Location = System::Drawing::Point(518, 162);
    this->petsLabel->Name = L"petsLabel";
    this->petsLabel->Size = System::Drawing::Size(45, 20);
    this->petsLabel->TabIndex = 3;
    this->petsLabel->Text = L"Pets";
    // 
    // childrenPanel
    // 
    this->childrenPanel->BackColor = System::Drawing::SystemColors::ControlLightLight;
    this->childrenPanel->Location = System::Drawing::Point(14, 245);
    this->childrenPanel->Name = L"childrenPanel";
    this->childrenPanel->Size = System::Drawing::Size(337, 331);
    this->childrenPanel->TabIndex = 4;
    // 
    // petsPanel
    // 
    this->petsPanel->BackColor = System::Drawing::SystemColors::ControlLightLight;
    this->petsPanel->Location = System::Drawing::Point(377, 245);
    this->petsPanel->Name = L"petsPanel";
    this->petsPanel->Size = System::Drawing::Size(337, 331);
    this->petsPanel->TabIndex = 5;
    // 
    // addChildButton
    // 
    this->addChildButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->addChildButton->Location = System::Drawing::Point(93, 185);
    this->addChildButton->Name = L"addChildButton";
    this->addChildButton->Size = System::Drawing::Size(180, 36);
    this->addChildButton->TabIndex = 6;
    this->addChildButton->Text = L"Add";
    this->addChildButton->UseVisualStyleBackColor = true;
    this->addChildButton->Click += gcnew System::EventHandler(this, &FamilyEditWindow::addChildButtonClick);
    // 
    // addPetButton
    // 
    this->addPetButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->addPetButton->Location = System::Drawing::Point(450, 185);
    this->addPetButton->Name = L"addPetButton";
    this->addPetButton->Size = System::Drawing::Size(180, 36);
    this->addPetButton->TabIndex = 7;
    this->addPetButton->Text = L"Add";
    this->addPetButton->UseVisualStyleBackColor = true;
    this->addPetButton->Click += gcnew System::EventHandler(this, &FamilyEditWindow::addPetButtonClick);
    // 
    // FamilyEditWindow
    // 
    this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
    this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
    this->ClientSize = System::Drawing::Size(821, 588);
    this->Controls->Add(this->addPetButton);
    this->Controls->Add(this->addChildButton);
    this->Controls->Add(this->petsPanel);
    this->Controls->Add(this->childrenPanel);
    this->Controls->Add(this->petsLabel);
    this->Controls->Add(this->childrenLabel);
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

void Project::FamilyEditWindow::LoadFamilyMemberUI()
{
    int i = 0;
    json serializedChildren = this->family.serialize()["children"];

    while (true) {
        json serializedChild = serializedChildren["child" + std::to_string(i)];
        if (serializedChild.is_null())
            break;

        AddChild(serializedChild);
        i++;
    }

    i = 0;
    json serializedPets = this->family.serialize()["pets"];
    while (true) {
        json serializedPet = serializedPets["pet" + std::to_string(i)];
        if (serializedPet.is_null())
            break;

        AddPet(serializedPet);
        i++;
    }
}

void Project::FamilyEditWindow::AddChild(const json& serializedObject)
{
    Child newChild = (serializedObject != "") ? 
        Child(serializedObject) : 
        Child{
            Project::Name("Name", "Surname"),
            Project::Date(1, 1, 2018),
            Project::PhoneNumber(std::string("missing")),
            Project::Gender::PANZERKAUMPFWAGEN,
    };

    if (serializedObject == "")
        this->family.addChild(newChild);
    // 
    // childPanel
    // 
    Panel^ childPanel = gcnew Panel();
    childPanel->Location = System::Drawing::Point(3, 
            0 + this->childrenPanel->Controls->Count * PANEL_SIZE);
    childPanel->Name = L"childPanel";
    childPanel->Size = System::Drawing::Size(331, 76);
    childPanel->TabIndex = 0;
    // 
    // childName
    // 
    Label^ childName = gcnew Label();
    childName->AutoSize = true;
    childName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    childName->Location = System::Drawing::Point(118, 10);
    childName->Name = L"childName";
    childName->Size = System::Drawing::Size(83, 16);
    childName->TabIndex = 0;
    childName->Text = 
        gcnew System::String(std::string(newChild.getName()).c_str());
    // 
    // childEditButton
    // 
    Button^ childEditButton = gcnew Button();
    childEditButton->BackColor = System::Drawing::SystemColors::ControlLight;
    childEditButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    childEditButton->Location = System::Drawing::Point(18, 45);
    childEditButton->Name = L"childEditButton";
    childEditButton->Size = System::Drawing::Size(123, 28);
    childEditButton->TabIndex = 1;
    childEditButton->Text = L"Edit";
    childEditButton->UseVisualStyleBackColor = false;
    childEditButton->Click += gcnew System::EventHandler(this, &FamilyEditWindow::onFamilyMemberEditButtonClick);
    // 
    // childRemoveButton
    // 
    Button^ childRemoveButton = gcnew Button();
    childRemoveButton->BackColor = System::Drawing::SystemColors::ControlLight;
    childRemoveButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    childRemoveButton->Location = System::Drawing::Point(187, 45);
    childRemoveButton->Name = L"childRemoveButton";
    childRemoveButton->Size = System::Drawing::Size(123, 28);
    childRemoveButton->TabIndex = 2;
    childRemoveButton->Text = L"Remove";
    childRemoveButton->UseVisualStyleBackColor = false; 
    childRemoveButton->Click += gcnew System::EventHandler(this, &FamilyEditWindow::removeChildButtonClick);


    childPanel->Controls->Add(childRemoveButton);
    childPanel->Controls->Add(childEditButton);
    childPanel->Controls->Add(childName);
    this->childrenPanel->Controls->Add(childPanel);
}

void Project::FamilyEditWindow::AddPet(const json& serializedObject)
{
    std::cout << "Added!" << std::endl;

    Pet newPet = (serializedObject != "") ?
        Pet(serializedObject) :
        Pet{
            "Name",
            Project::Date(1, 1, 2018),
            Project::PetType::DOG,
            10
    };

    if (serializedObject == "")
        this->family.addPet(newPet);
    // 
    // childPanel
    // 
    Panel^ petPanel = gcnew Panel();
    petPanel->Location = System::Drawing::Point(3,
        0 + this->petsPanel->Controls->Count * PANEL_SIZE);
    petPanel->Name = L"childPanel";
    petPanel->Size = System::Drawing::Size(331, 76);
    petPanel->TabIndex = 0;
    // 
    // childName
    // 
    Label^ petName = gcnew Label();
    petName->AutoSize = true;
    petName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    petName->Location = System::Drawing::Point(118, 10);
    petName->Name = L"childName";
    petName->Size = System::Drawing::Size(83, 16);
    petName->TabIndex = 0;
    petName->Text =
        gcnew System::String(std::string(newPet.getName()).c_str());
    // 
    // childEditButton
    // 
    Button^ petEditButton = gcnew Button();
    petEditButton->BackColor = System::Drawing::SystemColors::ControlLight;
    petEditButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    petEditButton->Location = System::Drawing::Point(18, 45);
    petEditButton->Name = L"childEditButton";
    petEditButton->Size = System::Drawing::Size(123, 28);
    petEditButton->TabIndex = 1;
    petEditButton->Text = L"Edit";
    petEditButton->UseVisualStyleBackColor = false;
    // 
    // childRemoveButton
    // 
    Button^ petRemoveButton = gcnew Button();
    petRemoveButton->BackColor = System::Drawing::SystemColors::ControlLight;
    petRemoveButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    petRemoveButton->Location = System::Drawing::Point(187, 45);
    petRemoveButton->Name = L"childRemoveButton";
    petRemoveButton->Size = System::Drawing::Size(123, 28);
    petRemoveButton->TabIndex = 2;
    petRemoveButton->Text = L"Remove";
    petRemoveButton->UseVisualStyleBackColor = false;
    petRemoveButton->Click += gcnew System::EventHandler(this, &FamilyEditWindow::removePetButtonClick);


    petPanel->Controls->Add(petRemoveButton);
    petPanel->Controls->Add(petEditButton);
    petPanel->Controls->Add(petName);
    this->petsPanel->Controls->Add(petPanel);
}

System::Void Project::FamilyEditWindow::addChildButtonClick(System::Object^ sender, System::EventArgs^ e)
{
    this->AddChild("");
}

System::Void Project::FamilyEditWindow::addPetButtonClick(System::Object^ sender, System::EventArgs^ e)
{
    this->AddPet("");
}

System::Void Project::FamilyEditWindow::removeChildButtonClick(System::Object^ sender, System::EventArgs^ e)
{
    Control^ layoutToDelete = safe_cast<Button^>(sender)->Parent;

    int layoutToDeleteId = this->childrenPanel->Controls->GetChildIndex(layoutToDelete);
    this->childrenPanel->Controls->Remove(layoutToDelete);
    this->family.deleteChild(layoutToDeleteId);

    fixLayoutAfterDelete(childrenPanel, PANEL_SIZE, layoutToDeleteId);
}

System::Void Project::FamilyEditWindow::removePetButtonClick(System::Object^ sender, System::EventArgs^ e)
{
    Control^ layoutToDelete = safe_cast<Button^>(sender)->Parent;

    int layoutToDeleteId = this->petsPanel->Controls->GetChildIndex(layoutToDelete);
    this->petsPanel->Controls->Remove(layoutToDelete);
    this->family.deletePet(layoutToDeleteId);

    fixLayoutAfterDelete(petsPanel, PANEL_SIZE, layoutToDeleteId);
}

System::Void Project::FamilyEditWindow::onFamilyNameTextChanged(System::Object^ sender, System::EventArgs^ e)
{
    TextBox^ familyNameTextBox = safe_cast<TextBox^>(sender);
    msclr::interop::marshal_context context;

    try
    {
        this->family.setName(
            context.marshal_as<std::string>(familyNameTextBox->Text)
        );
    }
    catch (System::ArgumentNullException^ e)
    {

    }
}

void invokeFamilyMemberEditWindow(Family& family, FamilyMember* familyMember)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    FamilyMemberEditWindow^ familyEditWindow = gcnew FamilyMemberEditWindow(family, *familyMember);
    Application::Run(familyEditWindow);
}

System::Void Project::FamilyEditWindow::onFamilyMemberEditButtonClick(System::Object^ sender, System::EventArgs^ e)
{
    Control^ targetLayout = safe_cast<Button^>(sender)->Parent;
    FamilyMember* pTargetFamilyMember = nullptr;

    if (safe_cast<Button^>(sender)->Name == "editFatherButton")
        pTargetFamilyMember = &(this->family.getFather());
    else if (safe_cast<Button^>(sender)->Name == "editMotherButton")
        pTargetFamilyMember = &(this->family.getMother());

    if (pTargetFamilyMember == nullptr)
    {
        int targetChildId = this->childrenPanel->Controls->GetChildIndex(targetLayout);
        pTargetFamilyMember = &this->family.getChild(targetChildId);
    }

    std::thread familyEditWindowProcess(invokeFamilyMemberEditWindow, std::ref(this->family), pTargetFamilyMember);
    familyEditWindowProcess.join();

//    Label^ labelToUpdate = safe_cast<Label^>(targetLayout->Controls["familyName"]);
//    labelToUpdate->Text =
//        gcnew String(std::string(this->families->at(targetChildId).getName()).c_str());
}
