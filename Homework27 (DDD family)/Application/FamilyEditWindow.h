#pragma once

namespace Project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class FamilyEditWindow : public System::Windows::Forms::Form
	{
	public:
		FamilyEditWindow(Family& family) : family(family)
		{
			InitializeComponent();
			LoadFamilyMemberUI();
		}

	protected:
		~FamilyEditWindow()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::ComponentModel::Container ^components;
		System::Windows::Forms::TextBox^ familyName;
		System::Windows::Forms::Panel^ parentsPanel;
		System::Windows::Forms::Label^ fatherLabel;
		System::Windows::Forms::Label^ motherLabel;
		System::Windows::Forms::Button^ editFatherButton;
		System::Windows::Forms::Button^ editMotherButton;
		System::Windows::Forms::Label^ childrenLabel;
		System::Windows::Forms::Label^ petsLabel;
		System::Windows::Forms::Panel^ childrenPanel;
		System::Windows::Forms::Panel^ petsPanel;
		System::Windows::Forms::Button^ addChildButton;
		System::Windows::Forms::Button^ addPetButton;

		Family& family;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void);

		void LoadFamilyMemberUI();

		void AddChild(const json& serializedObject);

		void AddPet(const json& serializedObject);

#pragma endregion
	private: System::Void addChildButtonClick(System::Object^ sender, System::EventArgs^ e);

	private: System::Void addPetButtonClick(System::Object^ sender, System::EventArgs^ e);

	private: System::Void removeChildButtonClick(System::Object^ sender, System::EventArgs^ e);

	private: System::Void removePetButtonClick(System::Object^ sender, System::EventArgs^ e);

	private: System::Void onFamilyMemberEditButtonClick(System::Object^ sender, System::EventArgs^ e);

	private: System::Void onFamilyNameTextChanged(System::Object^ sender, System::EventArgs^ e);

	};
}
