#pragma once

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace ZedGraph;

#define APP_VERSION		0.01
#define PART_NUMBER	"??"


	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			versionLbl->Text = "Current Version: " + double(APP_VERSION).ToString();
			partNumberLbl->Text = "Part number: " + PART_NUMBER;

			RedTX		= 0.640;
			RedTY		= 0.338; 
			GreenTX		= 0.337;
			GreenTY		= 0.613;
			BlueTX		= 0.157;
			BlueTY		= 0.054;

			/*
			RedBaseTX	= 0.66;
			RedBaseTY	= 0.33; 
			GreenBaseTX = 0.341;
			GreenBaseTY = 0.63;
			BlueBaseTX	= 0.140;
			BlueBaseTY	= 0.040; 
			*/
			RedBaseTX	= 0.640;
			RedBaseTY	= 0.338;
			GreenBaseTX = 0.337;
			GreenBaseTY = 0.613;
			BlueBaseTX	= 0.157;
			BlueBaseTY	= 0.054;


			WPTargetX = 0.313;
			WPTargetY = 0.329;
		
			WPCurX = 0.315;
			WPCurY = 0.31;

			RedTargetL		= 91.2;
			GreenTargetL	= 331;
			BlueTargetL		= 36;
			WhiteTargetL	= 445;

			RedBaseL		= 91.2;
			GreenBaseL		= 331;
			BlueBaseL		= 36;
			WhiteBaseL		= 445;


			RedTargetXVal->Text = double(RedTX).ToString();
			RedTargetYVal->Text = double(RedTY).ToString();

			GreenTargetXVal->Text = double(GreenTX).ToString();
			GreenTargetYVal->Text = double(GreenTY).ToString();

			BlueTargetXVal->Text = double(BlueTX).ToString();
			BlueTargetYVal->Text = double(BlueTY).ToString();

			WhiteTargetXVal->Text = double(WPTargetX).ToString();
			WhiteTargetYVal->Text = double(WPTargetY).ToString();


			RedBaseXVal->Text = double(RedBaseTX).ToString();
			RedBaseYVal->Text = double(RedBaseTY).ToString();

			GreenBaseXVal->Text = double(GreenBaseTX).ToString();
			GreenBaseYVal->Text = double(GreenBaseTY).ToString();

			BlueBaseXVal->Text = double(BlueBaseTX).ToString();
			BlueBaseYVal->Text = double(BlueBaseTY).ToString();

			WhiteBaseXVal->Text = double(WPCurX).ToString();
			WhiteBaseYVal->Text = double(WPCurY).ToString();


			RinVal->Text = int(255).ToString();
			GinVal->Text = int(0).ToString();
			BinVal->Text = int(0).ToString();

			RoutVal->Text = int(0).ToString();
			GoutVal->Text = int(0).ToString();
			BoutVal->Text = int(0).ToString();

			RedTargetLVal->Text		= double(RedTargetL).ToString();
			GreenTargetLVal->Text	= double(GreenTargetL).ToString();
			BlueTargetLVal->Text	= double(BlueTargetL).ToString();
			WhiteTargetLVal->Text	= double(WhiteTargetL).ToString();

			RedBaseLVal->Text	= double(RedBaseL).ToString();
			GreenBaseLVal->Text	= double(GreenBaseL).ToString();
			BlueBaseLVal->Text	= double(BlueBaseL).ToString();
			WhiteBaseLVal->Text	= double(WhiteBaseL).ToString();

			GABaseVal->Text = double(1).ToString();
			GATargetVal->Text = double(1).ToString();

			listBatchTestsChBox->Items->Add("R - range, B=G=0");
			listBatchTestsChBox->Items->Add("G - range, R=B=0");
			listBatchTestsChBox->Items->Add("B - range, R=G=0");

			listBatchTestsChBox->Items->Add("R - range, B=G=128");
			listBatchTestsChBox->Items->Add("G - range, R=B=128");
			listBatchTestsChBox->Items->Add("B - range, R=G=128");

			listBatchTestsChBox->Items->Add("R - range, B=G=255");
			listBatchTestsChBox->Items->Add("G - range, R=B=255");
			listBatchTestsChBox->Items->Add("B - range, R=G=255");

			listBatchTestsChBox->Items->Add("R,G - range, B=255");
			listBatchTestsChBox->Items->Add("G,B - range, R=255");
			listBatchTestsChBox->Items->Add("R,B - range, G=255");

			listBatchTestsChBox->Items->Add("R - range, G=0,B=255");
			listBatchTestsChBox->Items->Add("R - range, G=255,B=0");

			listBatchTestsChBox->Items->Add("G - range, R=0,B=255");
			listBatchTestsChBox->Items->Add("G - range, R=255,B=0");

			listBatchTestsChBox->Items->Add("B - range, R=0,G=255");
			listBatchTestsChBox->Items->Add("B - range, R=255,G=0");

			listShowResultsChBox->Items->Add("Show Original points");
			listShowResultsChBox->SetItemChecked(0, true);
			listShowResultsChBox->Items->Add("Show Corrected points");
			listShowResultsChBox->SetItemChecked(1, true);

			stepTextBox->Text = double(0.01).ToString();


			resultGraph->IsShowPointValues = true;
			zg1->IsShowPointValues = true;

			ClearResGraph();

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected: 

	private:
		double RedTX;
		double RedTY; 
		double GreenTX;
		double GreenTY;
		double BlueTX;
		double BlueTY;

		double RedBaseTX;
		double RedBaseTY; 
		double GreenBaseTX;
		double GreenBaseTY;
		double BlueBaseTX;
		double BlueBaseTY;

		double WPTargetX;
		double WPTargetY;
		
		double WPCurX;
		double WPCurY;


		double RedTargetL;
		double GreenTargetL;
		double BlueTargetL;
		double WhiteTargetL;
		
		double RedBaseL;
		double GreenBaseL;
		double BlueBaseL;	
		double WhiteBaseL;	

	private: ZedGraph::ZedGraphControl^  resultGraph;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label14;






	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::Label^  label18;


	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Label^  label16;


private: System::Windows::Forms::Button^  ApplyCoordinates;
private: System::Windows::Forms::Button^  ApplyCCT_correction;
private: System::Windows::Forms::Button^  ClearCalc;
private: System::Windows::Forms::Label^  GoutLbl;
private: System::Windows::Forms::Label^  BoutLbl;


private: System::Windows::Forms::Label^  RoutLbl;

private: System::Windows::Forms::TextBox^  BoutVal;
private: System::Windows::Forms::TextBox^  GoutVal;
private: System::Windows::Forms::TextBox^  RoutVal;
private: System::Windows::Forms::Label^  label19;
private: System::Windows::Forms::Label^  label20;
private: System::Windows::Forms::Label^  label21;



private: System::Windows::Forms::Label^  label29;
private: System::Windows::Forms::Label^  label30;
private: System::Windows::Forms::Label^  label31;
private: System::Windows::Forms::Label^  label32;




private: System::Windows::Forms::Label^  label25;
private: System::Windows::Forms::Label^  label26;
private: System::Windows::Forms::Label^  label27;
private: System::Windows::Forms::Label^  label28;






private: System::Windows::Forms::Label^  label34;


private: System::Windows::Forms::Label^  label33;

private: System::Windows::Forms::Label^  label37;
private: System::Windows::Forms::Label^  label38;
private: System::Windows::Forms::TextBox^  YOutVal;
private: System::Windows::Forms::TextBox^  XOutVal;
private: System::Windows::Forms::Label^  label35;
private: System::Windows::Forms::Label^  label36;
private: System::Windows::Forms::TextBox^  YInVal;
private: System::Windows::Forms::TextBox^  XInVal;
private: System::Windows::Forms::Button^  BatchCCT;
private: System::Windows::Forms::CheckedListBox^  listBatchTestsChBox;
private: System::Windows::Forms::CheckedListBox^  listShowResultsChBox;
private: System::Windows::Forms::GroupBox^  groupBox1;
private: System::Windows::Forms::Button^  MoveUpBtn;
private: System::Windows::Forms::CheckBox^  BaseSelectCoordChB;

private: System::Windows::Forms::Button^  MoveDownBtn;
private: System::Windows::Forms::CheckBox^  TargetSelectCoordChB;

private: System::Windows::Forms::Button^  MoveRightBtn;
private: System::Windows::Forms::Button^  MoveLeftBtn;
private: System::Windows::Forms::Label^  label39;

private: System::Windows::Forms::Button^  CollapseBtn;
private: System::Windows::Forms::Button^  ExpandBtn;
private: System::Windows::Forms::Label^  label40;

private: System::Windows::Forms::Button^  LumMinusBtn;
private: System::Windows::Forms::Button^  LumPlusBtn;
private: System::Windows::Forms::NumericUpDown^  GABaseVal;
private: System::Windows::Forms::NumericUpDown^  RedTargetXVal;
private: System::Windows::Forms::NumericUpDown^  WhiteBaseLVal;
private: System::Windows::Forms::NumericUpDown^  RedBaseXVal;
private: System::Windows::Forms::NumericUpDown^  BlueBaseLVal;
private: System::Windows::Forms::NumericUpDown^  GATargetVal;
private: System::Windows::Forms::NumericUpDown^  GreenBaseLVal;
private: System::Windows::Forms::NumericUpDown^  RedBaseLVal;
private: System::Windows::Forms::NumericUpDown^  WhiteBaseYVal;
private: System::Windows::Forms::NumericUpDown^  BlueBaseYVal;
private: System::Windows::Forms::NumericUpDown^  GreenBaseYVal;
private: System::Windows::Forms::NumericUpDown^  RedBaseYVal;
private: System::Windows::Forms::NumericUpDown^  WhiteBaseXVal;
private: System::Windows::Forms::NumericUpDown^  BlueBaseXVal;
private: System::Windows::Forms::NumericUpDown^  GreenBaseXVal;
private: System::Windows::Forms::NumericUpDown^  WhiteTargetLVal;
private: System::Windows::Forms::NumericUpDown^  BlueTargetLVal;
private: System::Windows::Forms::NumericUpDown^  GreenTargetLVal;
private: System::Windows::Forms::NumericUpDown^  RedTargetLVal;
private: System::Windows::Forms::NumericUpDown^  WhiteTargetYVal;
private: System::Windows::Forms::NumericUpDown^  BlueTargetYVal;
private: System::Windows::Forms::NumericUpDown^  GreenTargetYVal;
private: System::Windows::Forms::NumericUpDown^  RedTargetYVal;
private: System::Windows::Forms::NumericUpDown^  WhiteTargetXVal;
private: System::Windows::Forms::NumericUpDown^  BlueTargetXVal;
private: System::Windows::Forms::NumericUpDown^  GreenTargetXVal;
private: System::Windows::Forms::NumericUpDown^  BatchStepTxtBox;
private: System::Windows::Forms::NumericUpDown^  stepTextBox;
private: System::Windows::Forms::NumericUpDown^  BinVal;
private: System::Windows::Forms::NumericUpDown^  GinVal;
private: System::Windows::Forms::NumericUpDown^  RinVal;
private: System::Windows::Forms::GroupBox^  labelBox;

private: System::Windows::Forms::Label^  partNumberLbl;
private: System::Windows::Forms::Label^  versionLbl;

	private: System::Windows::Forms::Label^  label7;

			 

		void SetSize()
		{
			zg1->Location = Point( 10, 10 );
			// Leave a small margin around the outside of the control
			zg1->Size = System::Drawing::Size( ClientRectangle.Width - 360, ClientRectangle.Height/2 - 20 );
			
			resultGraph->Location = Point( 10, ClientRectangle.Height/2 );
			resultGraph->Size = System::Drawing::Size( ClientRectangle.Width - 360, ClientRectangle.Height/2 - 20 );

			DataGroupBox->Location = Point( ClientRectangle.Width - 345, 10 );
			DataGroupBox->Size = System::Drawing::Size( 340, ClientRectangle.Height - 100 );

			labelBox->Location = Point( ClientRectangle.Width - 345, ClientRectangle.Height - 90 );
		}

		System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e)
		{
			CreateGraph( zg1 );
			AddStartData(zg1);
			CreateGraph( resultGraph );
			SetSize();
		}

		System::Void Form1_Resize(System::Object^  sender, System::EventArgs^  e)
		{
			SetSize();
		}

		void AddStartData(ZedGraphControl ^z1 )
		{
			GraphPane ^myPane = z1->GraphPane;

			myPane->CurveList->Clear();

		// Make up some data points based on the Sine function
			PointPairList ^list = gcnew PointPairList();
			list->Add( System::Convert::ToDouble(RedTargetXVal->Text), System::Convert::ToDouble(RedTargetYVal->Text) );
			list->Add( System::Convert::ToDouble(GreenTargetXVal->Text), System::Convert::ToDouble(GreenTargetYVal->Text) );
			list->Add( System::Convert::ToDouble(BlueTargetXVal->Text), System::Convert::ToDouble(BlueTargetYVal->Text) );
			list->Add( System::Convert::ToDouble(RedTargetXVal->Text), System::Convert::ToDouble(RedTargetYVal->Text) );

			// Generate a red curve with diamond symbols, and "Alpha" in the legend
			LineItem ^myCurve = myPane->AddCurve( L"Target", list, Color::Red, SymbolType::Circle);
			// Fill the symbols with white
			myCurve->Symbol->Fill = gcnew Fill( Color::White );

			PointPairList ^listWPt = gcnew PointPairList();
			listWPt->Add(System::Convert::ToDouble(WhiteTargetXVal->Text), System::Convert::ToDouble(WhiteTargetYVal->Text));
			LineItem ^myCurveWPt = myPane->AddCurve(L"White Point target", listWPt, Color::Red, SymbolType::Circle);
			myCurveWPt->Symbol->Fill = gcnew Fill( Color::Red );
			
			PointPairList ^listWPb = gcnew PointPairList();
			listWPb->Add(System::Convert::ToDouble(WhiteBaseXVal->Text), System::Convert::ToDouble(WhiteBaseYVal->Text));
			LineItem ^myCurveWPb = myPane->AddCurve(L"White Point base", listWPb, Color::Blue, SymbolType::Circle);
			myCurveWPb->Symbol->Fill = gcnew Fill( Color::Blue );


			// Make up some data points based on the Sine function
			PointPairList ^listCur = gcnew PointPairList();
			listCur->Add( System::Convert::ToDouble(RedBaseXVal->Text), System::Convert::ToDouble(RedBaseYVal->Text) );
			listCur->Add( System::Convert::ToDouble(GreenBaseXVal->Text), System::Convert::ToDouble(GreenBaseYVal->Text) );
			listCur->Add( System::Convert::ToDouble(BlueBaseXVal->Text), System::Convert::ToDouble(BlueBaseYVal->Text) );
			listCur->Add( System::Convert::ToDouble(RedBaseXVal->Text), System::Convert::ToDouble(RedBaseYVal->Text) );

			// Generate a red curve with diamond symbols, and "Alpha" in the legend
			LineItem ^myCurveCur = myPane->AddCurve( L"Base", listCur, Color::Blue, SymbolType::Circle);
			// Fill the symbols with white
			myCurveCur->Symbol->Fill = gcnew Fill( Color::Blue );

			// Size the control to fit the window
			SetSize();

			// Tell ZedGraph to calculate the axis ranges
			// Note that you MUST call this after enabling IsAutoScrollRange, since AxisChange() sets
			// up the proper scrolling parameters
			z1->AxisChange();
			// Make sure the Graph gets redrawn
			z1->Invalidate();
		}

		void AddDataPoint(ZedGraphControl ^z1, double X, double Y, Color c )
		{
			GraphPane ^myPane = z1->GraphPane;
			PointPairList ^listP = gcnew PointPairList();
			listP->Add(X, Y);
			LineItem ^myCurveWP = myPane->AddCurve(L"", listP, Color::AntiqueWhite, SymbolType::Circle);
			myCurveWP->Symbol->Fill = gcnew Fill( c );
			// Tell ZedGraph to calculate the axis ranges
			// Note that you MUST call this after enabling IsAutoScrollRange, since AxisChange() sets
			// up the proper scrolling parameters
			z1->AxisChange();
			// Make sure the Graph gets redrawn
			z1->Invalidate();
		}

		void AddDataPointPair(ZedGraphControl ^z1, double X1, double Y1, double X2, double Y2, Color c )
		{
			GraphPane ^myPane = z1->GraphPane;
			PointPairList ^listP = gcnew PointPairList();
			listP->Add(X1, Y1);
			listP->Add(X2, Y2);
			LineItem ^myCurveWP = myPane->AddCurve(L"", listP, c, SymbolType::Circle);
			myCurveWP->Symbol->Fill = gcnew Fill( c );
			// Tell ZedGraph to calculate the axis ranges
			// Note that you MUST call this after enabling IsAutoScrollRange, since AxisChange() sets
			// up the proper scrolling parameters
			z1->AxisChange();
			// Make sure the Graph gets redrawn
			z1->Invalidate();
		}


		void CreateGraph( ZedGraphControl ^z1 )
		{
			// Get a reference to the GraphPane instance in the ZedGraphControl
			GraphPane ^myPane = z1->GraphPane;

			// Set the titles and axis labels
			myPane->Title->Text = L"GAMUT";
			myPane->XAxis->Title->Text = L"X";
			myPane->YAxis->Title->Text = L"Y";
			//myPane->Y2Axis->Title->Text = L"Parameter B";

			
			// Show the x axis grid
			myPane->XAxis->MajorGrid->IsVisible = true;

			myPane->XAxis->Scale->Min = 0.1;
			myPane->XAxis->Scale->Max = 0.7;

			// Make the Y axis scale red
			myPane->YAxis->Scale->FontSpec->FontColor = Color::Red;
			myPane->YAxis->Title->FontSpec->FontColor = Color::Red;
			// turn off the opposite tics so the Y tics don't show up on the Y2 axis
			myPane->YAxis->MajorTic->IsOpposite = false;
			myPane->YAxis->MinorTic->IsOpposite = false;
			// Don't display the Y zero line
			myPane->YAxis->MajorGrid->IsZeroLine = false;
			// Align the Y axis labels so they are flush to the axis
			myPane->YAxis->Scale->Align = AlignP::Inside;
			// Manually set the axis range
			myPane->YAxis->Scale->Min = 0;
			myPane->YAxis->Scale->Max = 0.7;

			// Fill the axis background with a gradient
			myPane->Chart->Fill = gcnew Fill( Color::White, Color::LightGray, 45.0f );

			// Add a text box with instructions
			/*TextObj ^text = gcnew TextObj(
				L"Zoom: left mouse & drag\nPan: middle mouse & drag\nContext Menu: right mouse",
				0.05f, 0.95f, CoordType::ChartFraction, AlignH::Left, AlignV::Bottom );
			text->FontSpec->StringAlignment = StringAlignment::Near;
			myPane->GraphObjList->Add( text );*/

			// Enable scrollbars if needed
			z1->IsShowHScrollBar = true;
			z1->IsShowVScrollBar = true;
			z1->IsAutoScrollRange = true;
			z1->IsScrollY2 = true;
		}
private: System::ComponentModel::IContainer^  components;
private: System::Windows::Forms::GroupBox^  DataGroupBox;











private: System::Windows::Forms::Label^  label3;
private: System::Windows::Forms::Label^  label2;
private: System::Windows::Forms::Label^  label1;
private: System::Windows::Forms::Label^  label4;
private: System::Windows::Forms::Label^  label5;
private: System::Windows::Forms::Label^  label6;



private: ZedGraph::ZedGraphControl^  zg1;



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->zg1 = (gcnew ZedGraph::ZedGraphControl());
			this->DataGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->labelBox = (gcnew System::Windows::Forms::GroupBox());
			this->partNumberLbl = (gcnew System::Windows::Forms::Label());
			this->versionLbl = (gcnew System::Windows::Forms::Label());
			this->BinVal = (gcnew System::Windows::Forms::NumericUpDown());
			this->BatchStepTxtBox = (gcnew System::Windows::Forms::NumericUpDown());
			this->GinVal = (gcnew System::Windows::Forms::NumericUpDown());
			this->WhiteBaseLVal = (gcnew System::Windows::Forms::NumericUpDown());
			this->RinVal = (gcnew System::Windows::Forms::NumericUpDown());
			this->RedBaseXVal = (gcnew System::Windows::Forms::NumericUpDown());
			this->BlueBaseLVal = (gcnew System::Windows::Forms::NumericUpDown());
			this->GATargetVal = (gcnew System::Windows::Forms::NumericUpDown());
			this->GreenBaseLVal = (gcnew System::Windows::Forms::NumericUpDown());
			this->RedTargetXVal = (gcnew System::Windows::Forms::NumericUpDown());
			this->RedBaseLVal = (gcnew System::Windows::Forms::NumericUpDown());
			this->GABaseVal = (gcnew System::Windows::Forms::NumericUpDown());
			this->WhiteBaseYVal = (gcnew System::Windows::Forms::NumericUpDown());
			this->label40 = (gcnew System::Windows::Forms::Label());
			this->BlueBaseYVal = (gcnew System::Windows::Forms::NumericUpDown());
			this->GreenBaseYVal = (gcnew System::Windows::Forms::NumericUpDown());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->stepTextBox = (gcnew System::Windows::Forms::NumericUpDown());
			this->LumMinusBtn = (gcnew System::Windows::Forms::Button());
			this->LumPlusBtn = (gcnew System::Windows::Forms::Button());
			this->CollapseBtn = (gcnew System::Windows::Forms::Button());
			this->ExpandBtn = (gcnew System::Windows::Forms::Button());
			this->label39 = (gcnew System::Windows::Forms::Label());
			this->MoveUpBtn = (gcnew System::Windows::Forms::Button());
			this->BaseSelectCoordChB = (gcnew System::Windows::Forms::CheckBox());
			this->MoveDownBtn = (gcnew System::Windows::Forms::Button());
			this->TargetSelectCoordChB = (gcnew System::Windows::Forms::CheckBox());
			this->MoveRightBtn = (gcnew System::Windows::Forms::Button());
			this->MoveLeftBtn = (gcnew System::Windows::Forms::Button());
			this->RedBaseYVal = (gcnew System::Windows::Forms::NumericUpDown());
			this->listShowResultsChBox = (gcnew System::Windows::Forms::CheckedListBox());
			this->WhiteBaseXVal = (gcnew System::Windows::Forms::NumericUpDown());
			this->BatchCCT = (gcnew System::Windows::Forms::Button());
			this->BlueBaseXVal = (gcnew System::Windows::Forms::NumericUpDown());
			this->listBatchTestsChBox = (gcnew System::Windows::Forms::CheckedListBox());
			this->GreenBaseXVal = (gcnew System::Windows::Forms::NumericUpDown());
			this->ApplyCoordinates = (gcnew System::Windows::Forms::Button());
			this->label37 = (gcnew System::Windows::Forms::Label());
			this->label38 = (gcnew System::Windows::Forms::Label());
			this->WhiteTargetLVal = (gcnew System::Windows::Forms::NumericUpDown());
			this->YOutVal = (gcnew System::Windows::Forms::TextBox());
			this->BlueTargetLVal = (gcnew System::Windows::Forms::NumericUpDown());
			this->XOutVal = (gcnew System::Windows::Forms::TextBox());
			this->GreenTargetLVal = (gcnew System::Windows::Forms::NumericUpDown());
			this->label35 = (gcnew System::Windows::Forms::Label());
			this->RedTargetLVal = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label36 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->WhiteTargetYVal = (gcnew System::Windows::Forms::NumericUpDown());
			this->YInVal = (gcnew System::Windows::Forms::TextBox());
			this->BlueTargetYVal = (gcnew System::Windows::Forms::NumericUpDown());
			this->GreenTargetYVal = (gcnew System::Windows::Forms::NumericUpDown());
			this->RedTargetYVal = (gcnew System::Windows::Forms::NumericUpDown());
			this->WhiteTargetXVal = (gcnew System::Windows::Forms::NumericUpDown());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->BlueTargetXVal = (gcnew System::Windows::Forms::NumericUpDown());
			this->GreenTargetXVal = (gcnew System::Windows::Forms::NumericUpDown());
			this->XInVal = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->GoutLbl = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->BoutLbl = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->RoutLbl = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->BoutVal = (gcnew System::Windows::Forms::TextBox());
			this->GoutVal = (gcnew System::Windows::Forms::TextBox());
			this->label34 = (gcnew System::Windows::Forms::Label());
			this->RoutVal = (gcnew System::Windows::Forms::TextBox());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label33 = (gcnew System::Windows::Forms::Label());
			this->ClearCalc = (gcnew System::Windows::Forms::Button());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->ApplyCCT_correction = (gcnew System::Windows::Forms::Button());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->resultGraph = (gcnew ZedGraph::ZedGraphControl());
			this->DataGroupBox->SuspendLayout();
			this->labelBox->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->BinVal))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->BatchStepTxtBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->GinVal))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->WhiteBaseLVal))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->RinVal))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->RedBaseXVal))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->BlueBaseLVal))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->GATargetVal))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->GreenBaseLVal))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->RedTargetXVal))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->RedBaseLVal))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->GABaseVal))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->WhiteBaseYVal))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->BlueBaseYVal))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->GreenBaseYVal))->BeginInit();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->stepTextBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->RedBaseYVal))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->WhiteBaseXVal))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->BlueBaseXVal))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->GreenBaseXVal))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->WhiteTargetLVal))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->BlueTargetLVal))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->GreenTargetLVal))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->RedTargetLVal))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->WhiteTargetYVal))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->BlueTargetYVal))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->GreenTargetYVal))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->RedTargetYVal))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->WhiteTargetXVal))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->BlueTargetXVal))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->GreenTargetXVal))->BeginInit();
			this->SuspendLayout();
			// 
			// zg1
			// 
			this->zg1->Location = System::Drawing::Point(12, 41);
			this->zg1->Name = L"zg1";
			this->zg1->ScrollGrace = 0;
			this->zg1->ScrollMaxX = 0;
			this->zg1->ScrollMaxY = 0;
			this->zg1->ScrollMaxY2 = 0;
			this->zg1->ScrollMinX = 0;
			this->zg1->ScrollMinY = 0;
			this->zg1->ScrollMinY2 = 0;
			this->zg1->Size = System::Drawing::Size(615, 454);
			this->zg1->TabIndex = 0;
			// 
			// DataGroupBox
			// 
			this->DataGroupBox->Controls->Add(this->BinVal);
			this->DataGroupBox->Controls->Add(this->BatchStepTxtBox);
			this->DataGroupBox->Controls->Add(this->GinVal);
			this->DataGroupBox->Controls->Add(this->WhiteBaseLVal);
			this->DataGroupBox->Controls->Add(this->RinVal);
			this->DataGroupBox->Controls->Add(this->RedBaseXVal);
			this->DataGroupBox->Controls->Add(this->BlueBaseLVal);
			this->DataGroupBox->Controls->Add(this->GATargetVal);
			this->DataGroupBox->Controls->Add(this->GreenBaseLVal);
			this->DataGroupBox->Controls->Add(this->RedTargetXVal);
			this->DataGroupBox->Controls->Add(this->RedBaseLVal);
			this->DataGroupBox->Controls->Add(this->GABaseVal);
			this->DataGroupBox->Controls->Add(this->WhiteBaseYVal);
			this->DataGroupBox->Controls->Add(this->label40);
			this->DataGroupBox->Controls->Add(this->BlueBaseYVal);
			this->DataGroupBox->Controls->Add(this->GreenBaseYVal);
			this->DataGroupBox->Controls->Add(this->groupBox1);
			this->DataGroupBox->Controls->Add(this->RedBaseYVal);
			this->DataGroupBox->Controls->Add(this->listShowResultsChBox);
			this->DataGroupBox->Controls->Add(this->WhiteBaseXVal);
			this->DataGroupBox->Controls->Add(this->BatchCCT);
			this->DataGroupBox->Controls->Add(this->BlueBaseXVal);
			this->DataGroupBox->Controls->Add(this->listBatchTestsChBox);
			this->DataGroupBox->Controls->Add(this->GreenBaseXVal);
			this->DataGroupBox->Controls->Add(this->ApplyCoordinates);
			this->DataGroupBox->Controls->Add(this->label37);
			this->DataGroupBox->Controls->Add(this->label38);
			this->DataGroupBox->Controls->Add(this->WhiteTargetLVal);
			this->DataGroupBox->Controls->Add(this->YOutVal);
			this->DataGroupBox->Controls->Add(this->BlueTargetLVal);
			this->DataGroupBox->Controls->Add(this->XOutVal);
			this->DataGroupBox->Controls->Add(this->GreenTargetLVal);
			this->DataGroupBox->Controls->Add(this->label35);
			this->DataGroupBox->Controls->Add(this->RedTargetLVal);
			this->DataGroupBox->Controls->Add(this->label1);
			this->DataGroupBox->Controls->Add(this->label36);
			this->DataGroupBox->Controls->Add(this->label2);
			this->DataGroupBox->Controls->Add(this->WhiteTargetYVal);
			this->DataGroupBox->Controls->Add(this->YInVal);
			this->DataGroupBox->Controls->Add(this->BlueTargetYVal);
			this->DataGroupBox->Controls->Add(this->GreenTargetYVal);
			this->DataGroupBox->Controls->Add(this->RedTargetYVal);
			this->DataGroupBox->Controls->Add(this->WhiteTargetXVal);
			this->DataGroupBox->Controls->Add(this->label3);
			this->DataGroupBox->Controls->Add(this->BlueTargetXVal);
			this->DataGroupBox->Controls->Add(this->GreenTargetXVal);
			this->DataGroupBox->Controls->Add(this->XInVal);
			this->DataGroupBox->Controls->Add(this->label6);
			this->DataGroupBox->Controls->Add(this->GoutLbl);
			this->DataGroupBox->Controls->Add(this->label5);
			this->DataGroupBox->Controls->Add(this->BoutLbl);
			this->DataGroupBox->Controls->Add(this->label4);
			this->DataGroupBox->Controls->Add(this->RoutLbl);
			this->DataGroupBox->Controls->Add(this->label7);
			this->DataGroupBox->Controls->Add(this->BoutVal);
			this->DataGroupBox->Controls->Add(this->GoutVal);
			this->DataGroupBox->Controls->Add(this->label34);
			this->DataGroupBox->Controls->Add(this->RoutVal);
			this->DataGroupBox->Controls->Add(this->label19);
			this->DataGroupBox->Controls->Add(this->label20);
			this->DataGroupBox->Controls->Add(this->label21);
			this->DataGroupBox->Controls->Add(this->label33);
			this->DataGroupBox->Controls->Add(this->ClearCalc);
			this->DataGroupBox->Controls->Add(this->label29);
			this->DataGroupBox->Controls->Add(this->ApplyCCT_correction);
			this->DataGroupBox->Controls->Add(this->label14);
			this->DataGroupBox->Controls->Add(this->label30);
			this->DataGroupBox->Controls->Add(this->label17);
			this->DataGroupBox->Controls->Add(this->label13);
			this->DataGroupBox->Controls->Add(this->label31);
			this->DataGroupBox->Controls->Add(this->label18);
			this->DataGroupBox->Controls->Add(this->label12);
			this->DataGroupBox->Controls->Add(this->label32);
			this->DataGroupBox->Controls->Add(this->label11);
			this->DataGroupBox->Controls->Add(this->label10);
			this->DataGroupBox->Controls->Add(this->label28);
			this->DataGroupBox->Controls->Add(this->label15);
			this->DataGroupBox->Controls->Add(this->label9);
			this->DataGroupBox->Controls->Add(this->label27);
			this->DataGroupBox->Controls->Add(this->label16);
			this->DataGroupBox->Controls->Add(this->label8);
			this->DataGroupBox->Controls->Add(this->label26);
			this->DataGroupBox->Controls->Add(this->label25);
			this->DataGroupBox->Location = System::Drawing::Point(658, 41);
			this->DataGroupBox->Name = L"DataGroupBox";
			this->DataGroupBox->Size = System::Drawing::Size(335, 1012);
			this->DataGroupBox->TabIndex = 1;
			this->DataGroupBox->TabStop = false;
			// 
			// labelBox
			// 
			this->labelBox->Controls->Add(this->partNumberLbl);
			this->labelBox->Controls->Add(this->versionLbl);
			this->labelBox->Location = System::Drawing::Point(658, 1119);
			this->labelBox->Name = L"labelBox";
			this->labelBox->Size = System::Drawing::Size(335, 37);
			this->labelBox->TabIndex = 89;
			this->labelBox->TabStop = false;
			// 
			// partNumberLbl
			// 
			this->partNumberLbl->AutoSize = true;
			this->partNumberLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->partNumberLbl->Location = System::Drawing::Point(106, 17);
			this->partNumberLbl->Name = L"partNumberLbl";
			this->partNumberLbl->Size = System::Drawing::Size(0, 13);
			this->partNumberLbl->TabIndex = 1;
			// 
			// versionLbl
			// 
			this->versionLbl->AutoSize = true;
			this->versionLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->versionLbl->Location = System::Drawing::Point(7, 18);
			this->versionLbl->Name = L"versionLbl";
			this->versionLbl->Size = System::Drawing::Size(0, 13);
			this->versionLbl->TabIndex = 0;
			// 
			// BinVal
			// 
			this->BinVal->Location = System::Drawing::Point(53, 487);
			this->BinVal->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {255, 0, 0, 0});
			this->BinVal->Name = L"BinVal";
			this->BinVal->Size = System::Drawing::Size(66, 20);
			this->BinVal->TabIndex = 5;
			this->BinVal->ValueChanged += gcnew System::EventHandler(this, &MyForm::BinVal_ValueChanged);
			// 
			// BatchStepTxtBox
			// 
			this->BatchStepTxtBox->Location = System::Drawing::Point(65, 672);
			this->BatchStepTxtBox->Name = L"BatchStepTxtBox";
			this->BatchStepTxtBox->Size = System::Drawing::Size(52, 20);
			this->BatchStepTxtBox->TabIndex = 3;
			this->BatchStepTxtBox->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {15, 0, 0, 0});
			// 
			// GinVal
			// 
			this->GinVal->Location = System::Drawing::Point(53, 461);
			this->GinVal->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {255, 0, 0, 0});
			this->GinVal->Name = L"GinVal";
			this->GinVal->Size = System::Drawing::Size(66, 20);
			this->GinVal->TabIndex = 4;
			this->GinVal->ValueChanged += gcnew System::EventHandler(this, &MyForm::GinVal_ValueChanged);
			// 
			// WhiteBaseLVal
			// 
			this->WhiteBaseLVal->DecimalPlaces = 1;
			this->WhiteBaseLVal->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, 65536});
			this->WhiteBaseLVal->Location = System::Drawing::Point(256, 258);
			this->WhiteBaseLVal->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1000, 0, 0, 0});
			this->WhiteBaseLVal->Name = L"WhiteBaseLVal";
			this->WhiteBaseLVal->Size = System::Drawing::Size(62, 20);
			this->WhiteBaseLVal->TabIndex = 24;
			this->WhiteBaseLVal->ValueChanged += gcnew System::EventHandler(this, &MyForm::WhiteBaseLVal_ValueChanged);
			// 
			// RinVal
			// 
			this->RinVal->Location = System::Drawing::Point(53, 435);
			this->RinVal->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {255, 0, 0, 0});
			this->RinVal->Name = L"RinVal";
			this->RinVal->Size = System::Drawing::Size(66, 20);
			this->RinVal->TabIndex = 3;
			this->RinVal->ValueChanged += gcnew System::EventHandler(this, &MyForm::RinVal_ValueChanged);
			// 
			// RedBaseXVal
			// 
			this->RedBaseXVal->DecimalPlaces = 3;
			this->RedBaseXVal->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 196608});
			this->RedBaseXVal->Location = System::Drawing::Point(70, 178);
			this->RedBaseXVal->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->RedBaseXVal->Name = L"RedBaseXVal";
			this->RedBaseXVal->Size = System::Drawing::Size(62, 20);
			this->RedBaseXVal->TabIndex = 25;
			this->RedBaseXVal->ValueChanged += gcnew System::EventHandler(this, &MyForm::RedBaseXVal_ValueChanged);
			// 
			// BlueBaseLVal
			// 
			this->BlueBaseLVal->DecimalPlaces = 1;
			this->BlueBaseLVal->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, 65536});
			this->BlueBaseLVal->Location = System::Drawing::Point(256, 230);
			this->BlueBaseLVal->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1000, 0, 0, 0});
			this->BlueBaseLVal->Name = L"BlueBaseLVal";
			this->BlueBaseLVal->Size = System::Drawing::Size(62, 20);
			this->BlueBaseLVal->TabIndex = 23;
			this->BlueBaseLVal->ValueChanged += gcnew System::EventHandler(this, &MyForm::BlueBaseLVal_ValueChanged);
			// 
			// GATargetVal
			// 
			this->GATargetVal->DecimalPlaces = 1;
			this->GATargetVal->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 65536});
			this->GATargetVal->Location = System::Drawing::Point(161, 140);
			this->GATargetVal->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {4, 0, 0, 0});
			this->GATargetVal->Name = L"GATargetVal";
			this->GATargetVal->Size = System::Drawing::Size(62, 20);
			this->GATargetVal->TabIndex = 26;
			this->GATargetVal->ValueChanged += gcnew System::EventHandler(this, &MyForm::GATargetVal_ValueChanged);
			// 
			// GreenBaseLVal
			// 
			this->GreenBaseLVal->DecimalPlaces = 1;
			this->GreenBaseLVal->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, 65536});
			this->GreenBaseLVal->Location = System::Drawing::Point(256, 204);
			this->GreenBaseLVal->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1000, 0, 0, 0});
			this->GreenBaseLVal->Name = L"GreenBaseLVal";
			this->GreenBaseLVal->Size = System::Drawing::Size(62, 20);
			this->GreenBaseLVal->TabIndex = 22;
			this->GreenBaseLVal->ValueChanged += gcnew System::EventHandler(this, &MyForm::GreenBaseLVal_ValueChanged);
			// 
			// RedTargetXVal
			// 
			this->RedTargetXVal->DecimalPlaces = 3;
			this->RedTargetXVal->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 196608});
			this->RedTargetXVal->Location = System::Drawing::Point(70, 34);
			this->RedTargetXVal->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->RedTargetXVal->Name = L"RedTargetXVal";
			this->RedTargetXVal->Size = System::Drawing::Size(61, 20);
			this->RedTargetXVal->TabIndex = 3;
			this->RedTargetXVal->ValueChanged += gcnew System::EventHandler(this, &MyForm::RedTargetXVal_ValueChanged);
			// 
			// RedBaseLVal
			// 
			this->RedBaseLVal->DecimalPlaces = 1;
			this->RedBaseLVal->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, 65536});
			this->RedBaseLVal->Location = System::Drawing::Point(256, 178);
			this->RedBaseLVal->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1000, 0, 0, 0});
			this->RedBaseLVal->Name = L"RedBaseLVal";
			this->RedBaseLVal->Size = System::Drawing::Size(62, 20);
			this->RedBaseLVal->TabIndex = 21;
			this->RedBaseLVal->ValueChanged += gcnew System::EventHandler(this, &MyForm::RedBaseLVal_ValueChanged);
			// 
			// GABaseVal
			// 
			this->GABaseVal->DecimalPlaces = 1;
			this->GABaseVal->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 65536});
			this->GABaseVal->Location = System::Drawing::Point(161, 285);
			this->GABaseVal->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {4, 0, 0, 0});
			this->GABaseVal->Name = L"GABaseVal";
			this->GABaseVal->Size = System::Drawing::Size(64, 20);
			this->GABaseVal->TabIndex = 3;
			this->GABaseVal->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->GABaseVal->ValueChanged += gcnew System::EventHandler(this, &MyForm::GABaseVal_ValueChanged);
			// 
			// WhiteBaseYVal
			// 
			this->WhiteBaseYVal->DecimalPlaces = 3;
			this->WhiteBaseYVal->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 196608});
			this->WhiteBaseYVal->Location = System::Drawing::Point(161, 259);
			this->WhiteBaseYVal->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->WhiteBaseYVal->Name = L"WhiteBaseYVal";
			this->WhiteBaseYVal->Size = System::Drawing::Size(62, 20);
			this->WhiteBaseYVal->TabIndex = 20;
			this->WhiteBaseYVal->ValueChanged += gcnew System::EventHandler(this, &MyForm::WhiteBaseYVal_ValueChanged);
			// 
			// label40
			// 
			this->label40->AutoSize = true;
			this->label40->Location = System::Drawing::Point(29, 674);
			this->label40->Name = L"label40";
			this->label40->Size = System::Drawing::Size(33, 13);
			this->label40->TabIndex = 88;
			this->label40->Text = L"step=";
			// 
			// BlueBaseYVal
			// 
			this->BlueBaseYVal->DecimalPlaces = 3;
			this->BlueBaseYVal->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 196608});
			this->BlueBaseYVal->Location = System::Drawing::Point(161, 230);
			this->BlueBaseYVal->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->BlueBaseYVal->Name = L"BlueBaseYVal";
			this->BlueBaseYVal->Size = System::Drawing::Size(62, 20);
			this->BlueBaseYVal->TabIndex = 19;
			this->BlueBaseYVal->ValueChanged += gcnew System::EventHandler(this, &MyForm::BlueBaseYVal_ValueChanged);
			// 
			// GreenBaseYVal
			// 
			this->GreenBaseYVal->DecimalPlaces = 3;
			this->GreenBaseYVal->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 196608});
			this->GreenBaseYVal->Location = System::Drawing::Point(161, 204);
			this->GreenBaseYVal->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->GreenBaseYVal->Name = L"GreenBaseYVal";
			this->GreenBaseYVal->Size = System::Drawing::Size(62, 20);
			this->GreenBaseYVal->TabIndex = 18;
			this->GreenBaseYVal->ValueChanged += gcnew System::EventHandler(this, &MyForm::GreenBaseYVal_ValueChanged);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->stepTextBox);
			this->groupBox1->Controls->Add(this->LumMinusBtn);
			this->groupBox1->Controls->Add(this->LumPlusBtn);
			this->groupBox1->Controls->Add(this->CollapseBtn);
			this->groupBox1->Controls->Add(this->ExpandBtn);
			this->groupBox1->Controls->Add(this->label39);
			this->groupBox1->Controls->Add(this->MoveUpBtn);
			this->groupBox1->Controls->Add(this->BaseSelectCoordChB);
			this->groupBox1->Controls->Add(this->MoveDownBtn);
			this->groupBox1->Controls->Add(this->TargetSelectCoordChB);
			this->groupBox1->Controls->Add(this->MoveRightBtn);
			this->groupBox1->Controls->Add(this->MoveLeftBtn);
			this->groupBox1->Location = System::Drawing::Point(11, 333);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(312, 86);
			this->groupBox1->TabIndex = 86;
			this->groupBox1->TabStop = false;
			// 
			// stepTextBox
			// 
			this->stepTextBox->DecimalPlaces = 2;
			this->stepTextBox->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 131072});
			this->stepTextBox->Location = System::Drawing::Point(115, 38);
			this->stepTextBox->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->stepTextBox->Name = L"stepTextBox";
			this->stepTextBox->Size = System::Drawing::Size(62, 20);
			this->stepTextBox->TabIndex = 3;
			this->stepTextBox->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 131072});
			// 
			// LumMinusBtn
			// 
			this->LumMinusBtn->Location = System::Drawing::Point(171, 61);
			this->LumMinusBtn->Name = L"LumMinusBtn";
			this->LumMinusBtn->Size = System::Drawing::Size(51, 23);
			this->LumMinusBtn->TabIndex = 91;
			this->LumMinusBtn->Text = L"Lum-";
			this->LumMinusBtn->UseVisualStyleBackColor = true;
			this->LumMinusBtn->Click += gcnew System::EventHandler(this, &MyForm::LumMinusBtn_Click);
			// 
			// LumPlusBtn
			// 
			this->LumPlusBtn->Location = System::Drawing::Point(171, 11);
			this->LumPlusBtn->Name = L"LumPlusBtn";
			this->LumPlusBtn->Size = System::Drawing::Size(51, 23);
			this->LumPlusBtn->TabIndex = 90;
			this->LumPlusBtn->Text = L"Lum+";
			this->LumPlusBtn->UseVisualStyleBackColor = true;
			this->LumPlusBtn->Click += gcnew System::EventHandler(this, &MyForm::LumPlusBtn_Click);
			// 
			// CollapseBtn
			// 
			this->CollapseBtn->Location = System::Drawing::Point(104, 61);
			this->CollapseBtn->Name = L"CollapseBtn";
			this->CollapseBtn->Size = System::Drawing::Size(60, 23);
			this->CollapseBtn->TabIndex = 89;
			this->CollapseBtn->Text = L"collapse";
			this->CollapseBtn->UseVisualStyleBackColor = true;
			this->CollapseBtn->Click += gcnew System::EventHandler(this, &MyForm::CollapseBtn_Click);
			// 
			// ExpandBtn
			// 
			this->ExpandBtn->Location = System::Drawing::Point(105, 11);
			this->ExpandBtn->Name = L"ExpandBtn";
			this->ExpandBtn->Size = System::Drawing::Size(60, 23);
			this->ExpandBtn->TabIndex = 88;
			this->ExpandBtn->Text = L"expand";
			this->ExpandBtn->UseVisualStyleBackColor = true;
			this->ExpandBtn->Click += gcnew System::EventHandler(this, &MyForm::ExpandBtn_Click);
			// 
			// label39
			// 
			this->label39->AutoSize = true;
			this->label39->Location = System::Drawing::Point(82, 40);
			this->label39->Name = L"label39";
			this->label39->Size = System::Drawing::Size(27, 13);
			this->label39->TabIndex = 87;
			this->label39->Text = L"step";
			// 
			// MoveUpBtn
			// 
			this->MoveUpBtn->Location = System::Drawing::Point(231, 19);
			this->MoveUpBtn->Name = L"MoveUpBtn";
			this->MoveUpBtn->Size = System::Drawing::Size(32, 23);
			this->MoveUpBtn->TabIndex = 80;
			this->MoveUpBtn->Text = L"U";
			this->MoveUpBtn->UseVisualStyleBackColor = true;
			this->MoveUpBtn->Click += gcnew System::EventHandler(this, &MyForm::MoveUpBtn_Click);
			// 
			// BaseSelectCoordChB
			// 
			this->BaseSelectCoordChB->AutoSize = true;
			this->BaseSelectCoordChB->Location = System::Drawing::Point(7, 48);
			this->BaseSelectCoordChB->Name = L"BaseSelectCoordChB";
			this->BaseSelectCoordChB->Size = System::Drawing::Size(50, 17);
			this->BaseSelectCoordChB->TabIndex = 85;
			this->BaseSelectCoordChB->Text = L"Base";
			this->BaseSelectCoordChB->UseVisualStyleBackColor = true;
			this->BaseSelectCoordChB->CheckedChanged += gcnew System::EventHandler(this, &MyForm::BaseSelectCoordChB_CheckedChanged);
			// 
			// MoveDownBtn
			// 
			this->MoveDownBtn->Location = System::Drawing::Point(231, 48);
			this->MoveDownBtn->Name = L"MoveDownBtn";
			this->MoveDownBtn->Size = System::Drawing::Size(32, 23);
			this->MoveDownBtn->TabIndex = 81;
			this->MoveDownBtn->Text = L"D";
			this->MoveDownBtn->UseVisualStyleBackColor = true;
			this->MoveDownBtn->Click += gcnew System::EventHandler(this, &MyForm::MoveDownBtn_Click);
			// 
			// TargetSelectCoordChB
			// 
			this->TargetSelectCoordChB->AutoSize = true;
			this->TargetSelectCoordChB->Location = System::Drawing::Point(7, 25);
			this->TargetSelectCoordChB->Name = L"TargetSelectCoordChB";
			this->TargetSelectCoordChB->Size = System::Drawing::Size(57, 17);
			this->TargetSelectCoordChB->TabIndex = 84;
			this->TargetSelectCoordChB->Text = L"Target";
			this->TargetSelectCoordChB->UseVisualStyleBackColor = true;
			this->TargetSelectCoordChB->CheckedChanged += gcnew System::EventHandler(this, &MyForm::TargetSelectCoordChB_CheckedChanged);
			// 
			// MoveRightBtn
			// 
			this->MoveRightBtn->Location = System::Drawing::Point(267, 37);
			this->MoveRightBtn->Name = L"MoveRightBtn";
			this->MoveRightBtn->Size = System::Drawing::Size(32, 23);
			this->MoveRightBtn->TabIndex = 82;
			this->MoveRightBtn->Text = L"R";
			this->MoveRightBtn->UseVisualStyleBackColor = true;
			this->MoveRightBtn->Click += gcnew System::EventHandler(this, &MyForm::MoveRightBtn_Click);
			// 
			// MoveLeftBtn
			// 
			this->MoveLeftBtn->Location = System::Drawing::Point(196, 37);
			this->MoveLeftBtn->Name = L"MoveLeftBtn";
			this->MoveLeftBtn->Size = System::Drawing::Size(32, 23);
			this->MoveLeftBtn->TabIndex = 83;
			this->MoveLeftBtn->Text = L"L";
			this->MoveLeftBtn->UseVisualStyleBackColor = true;
			this->MoveLeftBtn->Click += gcnew System::EventHandler(this, &MyForm::MoveLeftBtn_Click);
			// 
			// RedBaseYVal
			// 
			this->RedBaseYVal->DecimalPlaces = 3;
			this->RedBaseYVal->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 196608});
			this->RedBaseYVal->Location = System::Drawing::Point(161, 178);
			this->RedBaseYVal->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->RedBaseYVal->Name = L"RedBaseYVal";
			this->RedBaseYVal->Size = System::Drawing::Size(62, 20);
			this->RedBaseYVal->TabIndex = 17;
			this->RedBaseYVal->ValueChanged += gcnew System::EventHandler(this, &MyForm::RedBaseYVal_ValueChanged);
			// 
			// listShowResultsChBox
			// 
			this->listShowResultsChBox->FormattingEnabled = true;
			this->listShowResultsChBox->Location = System::Drawing::Point(18, 605);
			this->listShowResultsChBox->Name = L"listShowResultsChBox";
			this->listShowResultsChBox->Size = System::Drawing::Size(256, 49);
			this->listShowResultsChBox->TabIndex = 79;
			// 
			// WhiteBaseXVal
			// 
			this->WhiteBaseXVal->DecimalPlaces = 3;
			this->WhiteBaseXVal->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 196608});
			this->WhiteBaseXVal->Location = System::Drawing::Point(70, 259);
			this->WhiteBaseXVal->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->WhiteBaseXVal->Name = L"WhiteBaseXVal";
			this->WhiteBaseXVal->Size = System::Drawing::Size(62, 20);
			this->WhiteBaseXVal->TabIndex = 16;
			this->WhiteBaseXVal->ValueChanged += gcnew System::EventHandler(this, &MyForm::WhiteBaseXVal_ValueChanged);
			// 
			// BatchCCT
			// 
			this->BatchCCT->Location = System::Drawing::Point(19, 977);
			this->BatchCCT->Name = L"BatchCCT";
			this->BatchCCT->Size = System::Drawing::Size(123, 23);
			this->BatchCCT->TabIndex = 78;
			this->BatchCCT->Text = L"Batch CCT correction";
			this->BatchCCT->UseVisualStyleBackColor = true;
			this->BatchCCT->Click += gcnew System::EventHandler(this, &MyForm::BatchCCT_Click);
			// 
			// BlueBaseXVal
			// 
			this->BlueBaseXVal->DecimalPlaces = 3;
			this->BlueBaseXVal->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 196608});
			this->BlueBaseXVal->Location = System::Drawing::Point(69, 230);
			this->BlueBaseXVal->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->BlueBaseXVal->Name = L"BlueBaseXVal";
			this->BlueBaseXVal->Size = System::Drawing::Size(62, 20);
			this->BlueBaseXVal->TabIndex = 15;
			this->BlueBaseXVal->ValueChanged += gcnew System::EventHandler(this, &MyForm::BlueBaseXVal_ValueChanged);
			// 
			// listBatchTestsChBox
			// 
			this->listBatchTestsChBox->FormattingEnabled = true;
			this->listBatchTestsChBox->Location = System::Drawing::Point(18, 697);
			this->listBatchTestsChBox->Name = L"listBatchTestsChBox";
			this->listBatchTestsChBox->Size = System::Drawing::Size(256, 274);
			this->listBatchTestsChBox->TabIndex = 77;
			// 
			// GreenBaseXVal
			// 
			this->GreenBaseXVal->DecimalPlaces = 3;
			this->GreenBaseXVal->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 196608});
			this->GreenBaseXVal->Location = System::Drawing::Point(69, 204);
			this->GreenBaseXVal->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->GreenBaseXVal->Name = L"GreenBaseXVal";
			this->GreenBaseXVal->Size = System::Drawing::Size(62, 20);
			this->GreenBaseXVal->TabIndex = 14;
			this->GreenBaseXVal->ValueChanged += gcnew System::EventHandler(this, &MyForm::GreenBaseXVal_ValueChanged);
			// 
			// ApplyCoordinates
			// 
			this->ApplyCoordinates->Location = System::Drawing::Point(126, 310);
			this->ApplyCoordinates->Name = L"ApplyCoordinates";
			this->ApplyCoordinates->Size = System::Drawing::Size(104, 23);
			this->ApplyCoordinates->TabIndex = 34;
			this->ApplyCoordinates->Text = L"Apply Coordinates";
			this->ApplyCoordinates->UseVisualStyleBackColor = true;
			this->ApplyCoordinates->Click += gcnew System::EventHandler(this, &MyForm::ApplyCoordinates_Click);
			// 
			// label37
			// 
			this->label37->AutoSize = true;
			this->label37->Location = System::Drawing::Point(130, 526);
			this->label37->Name = L"label37";
			this->label37->Size = System::Drawing::Size(38, 13);
			this->label37->TabIndex = 76;
			this->label37->Text = L"Xout =";
			this->label37->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// label38
			// 
			this->label38->AutoSize = true;
			this->label38->Location = System::Drawing::Point(130, 552);
			this->label38->Name = L"label38";
			this->label38->Size = System::Drawing::Size(38, 13);
			this->label38->TabIndex = 75;
			this->label38->Text = L"Yout =";
			// 
			// WhiteTargetLVal
			// 
			this->WhiteTargetLVal->DecimalPlaces = 1;
			this->WhiteTargetLVal->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, 65536});
			this->WhiteTargetLVal->Location = System::Drawing::Point(256, 114);
			this->WhiteTargetLVal->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1000, 0, 0, 0});
			this->WhiteTargetLVal->Name = L"WhiteTargetLVal";
			this->WhiteTargetLVal->Size = System::Drawing::Size(62, 20);
			this->WhiteTargetLVal->TabIndex = 13;
			this->WhiteTargetLVal->ValueChanged += gcnew System::EventHandler(this, &MyForm::WhiteTargetLVal_ValueChanged);
			// 
			// YOutVal
			// 
			this->YOutVal->Location = System::Drawing::Point(168, 549);
			this->YOutVal->Name = L"YOutVal";
			this->YOutVal->ReadOnly = true;
			this->YOutVal->Size = System::Drawing::Size(64, 20);
			this->YOutVal->TabIndex = 74;
			// 
			// BlueTargetLVal
			// 
			this->BlueTargetLVal->DecimalPlaces = 1;
			this->BlueTargetLVal->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, 65536});
			this->BlueTargetLVal->Location = System::Drawing::Point(256, 86);
			this->BlueTargetLVal->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1000, 0, 0, 0});
			this->BlueTargetLVal->Name = L"BlueTargetLVal";
			this->BlueTargetLVal->Size = System::Drawing::Size(62, 20);
			this->BlueTargetLVal->TabIndex = 12;
			this->BlueTargetLVal->ValueChanged += gcnew System::EventHandler(this, &MyForm::BlueTargetLVal_ValueChanged);
			// 
			// XOutVal
			// 
			this->XOutVal->Location = System::Drawing::Point(168, 523);
			this->XOutVal->Name = L"XOutVal";
			this->XOutVal->ReadOnly = true;
			this->XOutVal->Size = System::Drawing::Size(64, 20);
			this->XOutVal->TabIndex = 73;
			// 
			// GreenTargetLVal
			// 
			this->GreenTargetLVal->DecimalPlaces = 1;
			this->GreenTargetLVal->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, 65536});
			this->GreenTargetLVal->Location = System::Drawing::Point(256, 60);
			this->GreenTargetLVal->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1000, 0, 0, 0});
			this->GreenTargetLVal->Name = L"GreenTargetLVal";
			this->GreenTargetLVal->Size = System::Drawing::Size(62, 20);
			this->GreenTargetLVal->TabIndex = 11;
			this->GreenTargetLVal->ValueChanged += gcnew System::EventHandler(this, &MyForm::GreenTargetLVal_ValueChanged);
			// 
			// label35
			// 
			this->label35->AutoSize = true;
			this->label35->Location = System::Drawing::Point(15, 526);
			this->label35->Name = L"label35";
			this->label35->Size = System::Drawing::Size(31, 13);
			this->label35->TabIndex = 72;
			this->label35->Text = L"Xin =";
			this->label35->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// RedTargetLVal
			// 
			this->RedTargetLVal->DecimalPlaces = 1;
			this->RedTargetLVal->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, 65536});
			this->RedTargetLVal->Location = System::Drawing::Point(256, 34);
			this->RedTargetLVal->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1000, 0, 0, 0});
			this->RedTargetLVal->Name = L"RedTargetLVal";
			this->RedTargetLVal->Size = System::Drawing::Size(62, 20);
			this->RedTargetLVal->TabIndex = 10;
			this->RedTargetLVal->ValueChanged += gcnew System::EventHandler(this, &MyForm::RedTargetLVal_ValueChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(16, 36);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(46, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Red X =";
			// 
			// label36
			// 
			this->label36->AutoSize = true;
			this->label36->Location = System::Drawing::Point(15, 552);
			this->label36->Name = L"label36";
			this->label36->Size = System::Drawing::Size(31, 13);
			this->label36->TabIndex = 71;
			this->label36->Text = L"Yin =";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(15, 88);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(47, 13);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Blue X =";
			// 
			// WhiteTargetYVal
			// 
			this->WhiteTargetYVal->DecimalPlaces = 3;
			this->WhiteTargetYVal->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 196608});
			this->WhiteTargetYVal->Location = System::Drawing::Point(161, 114);
			this->WhiteTargetYVal->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->WhiteTargetYVal->Name = L"WhiteTargetYVal";
			this->WhiteTargetYVal->Size = System::Drawing::Size(62, 20);
			this->WhiteTargetYVal->TabIndex = 9;
			this->WhiteTargetYVal->ValueChanged += gcnew System::EventHandler(this, &MyForm::WhiteTargetYVal_ValueChanged);
			// 
			// YInVal
			// 
			this->YInVal->Location = System::Drawing::Point(53, 549);
			this->YInVal->Name = L"YInVal";
			this->YInVal->ReadOnly = true;
			this->YInVal->Size = System::Drawing::Size(64, 20);
			this->YInVal->TabIndex = 70;
			// 
			// BlueTargetYVal
			// 
			this->BlueTargetYVal->DecimalPlaces = 3;
			this->BlueTargetYVal->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 196608});
			this->BlueTargetYVal->Location = System::Drawing::Point(161, 86);
			this->BlueTargetYVal->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->BlueTargetYVal->Name = L"BlueTargetYVal";
			this->BlueTargetYVal->Size = System::Drawing::Size(62, 20);
			this->BlueTargetYVal->TabIndex = 8;
			this->BlueTargetYVal->ValueChanged += gcnew System::EventHandler(this, &MyForm::BlueTargetYVal_ValueChanged);
			// 
			// GreenTargetYVal
			// 
			this->GreenTargetYVal->DecimalPlaces = 3;
			this->GreenTargetYVal->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 196608});
			this->GreenTargetYVal->Location = System::Drawing::Point(161, 60);
			this->GreenTargetYVal->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->GreenTargetYVal->Name = L"GreenTargetYVal";
			this->GreenTargetYVal->Size = System::Drawing::Size(62, 20);
			this->GreenTargetYVal->TabIndex = 7;
			this->GreenTargetYVal->ValueChanged += gcnew System::EventHandler(this, &MyForm::GreenTargetYVal_ValueChanged);
			// 
			// RedTargetYVal
			// 
			this->RedTargetYVal->DecimalPlaces = 3;
			this->RedTargetYVal->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 196608});
			this->RedTargetYVal->Location = System::Drawing::Point(161, 34);
			this->RedTargetYVal->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->RedTargetYVal->Name = L"RedTargetYVal";
			this->RedTargetYVal->Size = System::Drawing::Size(62, 20);
			this->RedTargetYVal->TabIndex = 6;
			this->RedTargetYVal->ValueChanged += gcnew System::EventHandler(this, &MyForm::RedTargetYVal_ValueChanged);
			// 
			// WhiteTargetXVal
			// 
			this->WhiteTargetXVal->DecimalPlaces = 3;
			this->WhiteTargetXVal->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 196608});
			this->WhiteTargetXVal->Location = System::Drawing::Point(70, 114);
			this->WhiteTargetXVal->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->WhiteTargetXVal->Name = L"WhiteTargetXVal";
			this->WhiteTargetXVal->Size = System::Drawing::Size(62, 20);
			this->WhiteTargetXVal->TabIndex = 5;
			this->WhiteTargetXVal->ValueChanged += gcnew System::EventHandler(this, &MyForm::WhiteTargetXVal_ValueChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(7, 62);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(55, 13);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Green X =";
			this->label3->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// BlueTargetXVal
			// 
			this->BlueTargetXVal->DecimalPlaces = 3;
			this->BlueTargetXVal->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 196608});
			this->BlueTargetXVal->Location = System::Drawing::Point(70, 86);
			this->BlueTargetXVal->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->BlueTargetXVal->Name = L"BlueTargetXVal";
			this->BlueTargetXVal->Size = System::Drawing::Size(62, 20);
			this->BlueTargetXVal->TabIndex = 4;
			this->BlueTargetXVal->ValueChanged += gcnew System::EventHandler(this, &MyForm::BlueTargetXVal_ValueChanged);
			// 
			// GreenTargetXVal
			// 
			this->GreenTargetXVal->DecimalPlaces = 3;
			this->GreenTargetXVal->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 196608});
			this->GreenTargetXVal->Location = System::Drawing::Point(70, 60);
			this->GreenTargetXVal->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->GreenTargetXVal->Name = L"GreenTargetXVal";
			this->GreenTargetXVal->Size = System::Drawing::Size(62, 20);
			this->GreenTargetXVal->TabIndex = 3;
			this->GreenTargetXVal->ValueChanged += gcnew System::EventHandler(this, &MyForm::GreenTargetXVal_ValueChanged);
			// 
			// XInVal
			// 
			this->XInVal->Location = System::Drawing::Point(53, 523);
			this->XInVal->Name = L"XInVal";
			this->XInVal->ReadOnly = true;
			this->XInVal->Size = System::Drawing::Size(64, 20);
			this->XInVal->TabIndex = 69;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(138, 36);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(23, 13);
			this->label6->TabIndex = 9;
			this->label6->Text = L"Y =";
			// 
			// GoutLbl
			// 
			this->GoutLbl->AutoSize = true;
			this->GoutLbl->Location = System::Drawing::Point(130, 463);
			this->GoutLbl->Name = L"GoutLbl";
			this->GoutLbl->Size = System::Drawing::Size(39, 13);
			this->GoutLbl->TabIndex = 48;
			this->GoutLbl->Text = L"Gout =";
			this->GoutLbl->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(138, 88);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(20, 13);
			this->label5->TabIndex = 10;
			this->label5->Text = L"Y=";
			// 
			// BoutLbl
			// 
			this->BoutLbl->AutoSize = true;
			this->BoutLbl->Location = System::Drawing::Point(130, 489);
			this->BoutLbl->Name = L"BoutLbl";
			this->BoutLbl->Size = System::Drawing::Size(38, 13);
			this->BoutLbl->TabIndex = 47;
			this->BoutLbl->Text = L"Bout =";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(138, 62);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(23, 13);
			this->label4->TabIndex = 11;
			this->label4->Text = L"Y =";
			this->label4->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// RoutLbl
			// 
			this->RoutLbl->AutoSize = true;
			this->RoutLbl->Location = System::Drawing::Point(130, 437);
			this->RoutLbl->Name = L"RoutLbl";
			this->RoutLbl->Size = System::Drawing::Size(39, 13);
			this->RoutLbl->TabIndex = 46;
			this->RoutLbl->Text = L"Rout =";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(100, 16);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(38, 13);
			this->label7->TabIndex = 12;
			this->label7->Text = L"Target";
			// 
			// BoutVal
			// 
			this->BoutVal->Location = System::Drawing::Point(168, 486);
			this->BoutVal->Name = L"BoutVal";
			this->BoutVal->ReadOnly = true;
			this->BoutVal->Size = System::Drawing::Size(64, 20);
			this->BoutVal->TabIndex = 45;
			this->BoutVal->TextChanged += gcnew System::EventHandler(this, &MyForm::BoutVal_TextChanged);
			// 
			// GoutVal
			// 
			this->GoutVal->Location = System::Drawing::Point(168, 460);
			this->GoutVal->Name = L"GoutVal";
			this->GoutVal->ReadOnly = true;
			this->GoutVal->Size = System::Drawing::Size(64, 20);
			this->GoutVal->TabIndex = 44;
			this->GoutVal->TextChanged += gcnew System::EventHandler(this, &MyForm::GoutVal_TextChanged);
			// 
			// label34
			// 
			this->label34->AutoSize = true;
			this->label34->Location = System::Drawing::Point(123, 287);
			this->label34->Name = L"label34";
			this->label34->Size = System::Drawing::Size(34, 13);
			this->label34->TabIndex = 68;
			this->label34->Text = L"GAb=";
			// 
			// RoutVal
			// 
			this->RoutVal->Location = System::Drawing::Point(168, 434);
			this->RoutVal->Name = L"RoutVal";
			this->RoutVal->ReadOnly = true;
			this->RoutVal->Size = System::Drawing::Size(64, 20);
			this->RoutVal->TabIndex = 43;
			this->RoutVal->TextChanged += gcnew System::EventHandler(this, &MyForm::RoutVal_TextChanged);
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(15, 463);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(32, 13);
			this->label19->TabIndex = 42;
			this->label19->Text = L"Gin =";
			this->label19->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(15, 489);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(31, 13);
			this->label20->TabIndex = 41;
			this->label20->Text = L"Bin =";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(15, 437);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(32, 13);
			this->label21->TabIndex = 40;
			this->label21->Text = L"Rin =";
			// 
			// label33
			// 
			this->label33->AutoSize = true;
			this->label33->Location = System::Drawing::Point(126, 142);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(31, 13);
			this->label33->TabIndex = 66;
			this->label33->Text = L"GAt=";
			// 
			// ClearCalc
			// 
			this->ClearCalc->Location = System::Drawing::Point(22, 575);
			this->ClearCalc->Name = L"ClearCalc";
			this->ClearCalc->Size = System::Drawing::Size(123, 23);
			this->ClearCalc->TabIndex = 36;
			this->ClearCalc->Text = L"Clear";
			this->ClearCalc->UseVisualStyleBackColor = true;
			this->ClearCalc->Click += gcnew System::EventHandler(this, &MyForm::ClearCalc_Click);
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Location = System::Drawing::Point(231, 260);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(19, 13);
			this->label29->TabIndex = 64;
			this->label29->Text = L"L=";
			// 
			// ApplyCCT_correction
			// 
			this->ApplyCCT_correction->Location = System::Drawing::Point(151, 575);
			this->ApplyCCT_correction->Name = L"ApplyCCT_correction";
			this->ApplyCCT_correction->Size = System::Drawing::Size(123, 23);
			this->ApplyCCT_correction->TabIndex = 35;
			this->ApplyCCT_correction->Text = L"Apply CCT correction";
			this->ApplyCCT_correction->UseVisualStyleBackColor = true;
			this->ApplyCCT_correction->Click += gcnew System::EventHandler(this, &MyForm::ApplyCCT_correction_Click);
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(16, 180);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(46, 13);
			this->label14->TabIndex = 19;
			this->label14->Text = L"Red X =";
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->Location = System::Drawing::Point(231, 206);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(19, 13);
			this->label30->TabIndex = 63;
			this->label30->Text = L"L=";
			this->label30->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(138, 261);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(20, 13);
			this->label17->TabIndex = 33;
			this->label17->Text = L"Y=";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(15, 232);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(47, 13);
			this->label13->TabIndex = 20;
			this->label13->Text = L"Blue X =";
			// 
			// label31
			// 
			this->label31->AutoSize = true;
			this->label31->Location = System::Drawing::Point(231, 232);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(19, 13);
			this->label31->TabIndex = 62;
			this->label31->Text = L"L=";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(8, 261);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(54, 13);
			this->label18->TabIndex = 32;
			this->label18->Text = L"White X =";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(7, 206);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(55, 13);
			this->label12->TabIndex = 21;
			this->label12->Text = L"Green X =";
			this->label12->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->Location = System::Drawing::Point(231, 180);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(19, 13);
			this->label32->TabIndex = 61;
			this->label32->Text = L"L=";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(138, 180);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(23, 13);
			this->label11->TabIndex = 22;
			this->label11->Text = L"Y =";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(138, 232);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(20, 13);
			this->label10->TabIndex = 23;
			this->label10->Text = L"Y=";
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Location = System::Drawing::Point(231, 36);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(19, 13);
			this->label28->TabIndex = 53;
			this->label28->Text = L"L=";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(138, 116);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(20, 13);
			this->label15->TabIndex = 29;
			this->label15->Text = L"Y=";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(138, 206);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(23, 13);
			this->label9->TabIndex = 24;
			this->label9->Text = L"Y =";
			this->label9->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Location = System::Drawing::Point(231, 88);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(19, 13);
			this->label27->TabIndex = 54;
			this->label27->Text = L"L=";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(8, 116);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(54, 13);
			this->label16->TabIndex = 28;
			this->label16->Text = L"White X =";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(100, 160);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(31, 13);
			this->label8->TabIndex = 25;
			this->label8->Text = L"Base";
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Location = System::Drawing::Point(231, 62);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(19, 13);
			this->label26->TabIndex = 55;
			this->label26->Text = L"L=";
			this->label26->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Location = System::Drawing::Point(231, 116);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(19, 13);
			this->label25->TabIndex = 56;
			this->label25->Text = L"L=";
			// 
			// resultGraph
			// 
			this->resultGraph->Location = System::Drawing::Point(12, 518);
			this->resultGraph->Name = L"resultGraph";
			this->resultGraph->ScrollGrace = 0;
			this->resultGraph->ScrollMaxX = 0;
			this->resultGraph->ScrollMaxY = 0;
			this->resultGraph->ScrollMaxY2 = 0;
			this->resultGraph->ScrollMinX = 0;
			this->resultGraph->ScrollMinY = 0;
			this->resultGraph->ScrollMinY2 = 0;
			this->resultGraph->Size = System::Drawing::Size(615, 454);
			this->resultGraph->TabIndex = 2;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1004, 1168);
			this->Controls->Add(this->labelBox);
			this->Controls->Add(this->resultGraph);
			this->Controls->Add(this->DataGroupBox);
			this->Controls->Add(this->zg1);
			this->Location = System::Drawing::Point(12, 12);
			this->Name = L"MyForm";
			this->Text = L"CCT demo";
			this->Load += gcnew System::EventHandler(this, &MyForm::Form1_Load);
			this->Resize += gcnew System::EventHandler(this, &MyForm::Form1_Resize);
			this->DataGroupBox->ResumeLayout(false);
			this->DataGroupBox->PerformLayout();
			this->labelBox->ResumeLayout(false);
			this->labelBox->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->BinVal))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->BatchStepTxtBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->GinVal))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->WhiteBaseLVal))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->RinVal))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->RedBaseXVal))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->BlueBaseLVal))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->GATargetVal))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->GreenBaseLVal))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->RedTargetXVal))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->RedBaseLVal))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->GABaseVal))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->WhiteBaseYVal))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->BlueBaseYVal))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->GreenBaseYVal))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->stepTextBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->RedBaseYVal))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->WhiteBaseXVal))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->BlueBaseXVal))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->GreenBaseXVal))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->WhiteTargetLVal))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->BlueTargetLVal))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->GreenTargetLVal))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->RedTargetLVal))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->WhiteTargetYVal))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->BlueTargetYVal))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->GreenTargetYVal))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->RedTargetYVal))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->WhiteTargetXVal))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->BlueTargetXVal))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->GreenTargetXVal))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

		System::Void RefreshGraphs()
		{
			AddStartData(zg1);
			ClearResGraph();
			ApplyPointCorrection();
			ApplyBatchCorrection();
		}

private: System::Void ApplyCoordinates_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 RefreshGraphs();
		 }

private:System::Void CalcRGB2XY(double Rin, double Gin, double Bin, double& x, double& y, double& Lw)
		{
			double Xbase[3];
			double Ybase[3];
			double Lbase[3];
			

			int RED = 0;
			int GREEN = 1;
			int BLUE = 2;
			double GAbase = System::Convert::ToDouble(GABaseVal->Text);
			
			Xbase[RED]	= System::Convert::ToDouble(RedBaseXVal->Text);			
			Ybase[RED]	= System::Convert::ToDouble(RedBaseYVal->Text);	
			Lbase[RED]	= System::Convert::ToDouble(RedBaseLVal->Text);	
			
			Xbase[GREEN]= System::Convert::ToDouble(GreenBaseXVal->Text);
			Ybase[GREEN]= System::Convert::ToDouble(GreenBaseYVal->Text);
			Lbase[GREEN]= System::Convert::ToDouble(GreenBaseLVal->Text);

			Xbase[BLUE] = System::Convert::ToDouble(BlueBaseXVal->Text);	
			Ybase[BLUE]	= System::Convert::ToDouble(BlueBaseYVal->Text);	
			Lbase[BLUE] = System::Convert::ToDouble(BlueBaseLVal->Text);	


			double Lrbase = Lbase[RED] * Math::Pow(Rin, GAbase);
			double Lgbase = Lbase[GREEN] * Math::Pow(Gin, GAbase);
			double Lbbase = Lbase[BLUE] * Math::Pow(Bin, GAbase);
			Lw = Lrbase + Lgbase + Lbbase;

			x = (Lrbase * Xbase[RED]/Ybase[RED] + Lgbase * Xbase[GREEN]/Ybase[GREEN] + Lbbase * Xbase[BLUE]/Ybase[BLUE]) / 
				(Lrbase/Ybase[RED] + Lgbase/Ybase[GREEN] + Lbbase/Ybase[BLUE]);
			y = (Lrbase + Lgbase + Lbbase) / (Lrbase/Ybase[RED] + Lgbase/Ybase[GREEN] + Lbbase/Ybase[BLUE]);		
		}

private:System::Void CalcTargetRGB2XY(double Rin, double Gin, double Bin, double& x, double& y, double& Lw)
		{
			double Xtarget[3];
			double Ytarget[3];
			double Ltarget[3];
			

			int RED = 0;
			int GREEN = 1;
			int BLUE = 2;
			double GAtarget = System::Convert::ToDouble(GATargetVal->Text);
			
			Xtarget[RED]	= System::Convert::ToDouble(RedTargetXVal->Text);			
			Ytarget[RED]	= System::Convert::ToDouble(RedTargetYVal->Text);	
			Ltarget[RED]	= System::Convert::ToDouble(RedTargetLVal->Text);	
			
			Xtarget[GREEN]	= System::Convert::ToDouble(GreenTargetXVal->Text);
			Ytarget[GREEN]	= System::Convert::ToDouble(GreenTargetYVal->Text);
			Ltarget[GREEN]	= System::Convert::ToDouble(GreenTargetLVal->Text);

			Xtarget[BLUE]	= System::Convert::ToDouble(BlueTargetXVal->Text);	
			Ytarget[BLUE]	= System::Convert::ToDouble(BlueTargetYVal->Text);	
			Ltarget[BLUE]	= System::Convert::ToDouble(BlueTargetLVal->Text);	


			double Lrtarget = Ltarget[RED] * Math::Pow(Rin, GAtarget);
			double Lgtarget = Ltarget[GREEN] * Math::Pow(Gin, GAtarget);
			double Lbtarget = Ltarget[BLUE] * Math::Pow(Bin, GAtarget);
			Lw = Lrtarget + Lgtarget + Lbtarget;

			x = (Lrtarget * Xtarget[RED] / Ytarget[RED] + Lgtarget * Xtarget[GREEN] / Ytarget[GREEN] + Lbtarget * Xtarget[BLUE] / Ytarget[BLUE]) / 
				(Lrtarget/Ytarget[RED] + Lgtarget / Ytarget[GREEN] + Lbtarget / Ytarget[BLUE]);
			y = (Lrtarget + Lgtarget + Lbtarget) / (Lrtarget / Ytarget[RED] + Lgtarget / Ytarget[GREEN] + Lbtarget / Ytarget[BLUE]);
		}


private:System::Void TransfomXY2RGB(double x, double y, double Lw, double& R, double& G, double& B)
		{
			double Xtarget[3];
			double Ytarget[3];
			double Ltarget[3];
			double GAtarget = System::Convert::ToDouble(GATargetVal->Text);
			int RED = 0;
			int GREEN = 1;
			int BLUE = 2;

			Xtarget[RED]	= System::Convert::ToDouble(RedTargetXVal->Text);
			Ytarget[RED]	= System::Convert::ToDouble(RedTargetYVal->Text);
			Ltarget[RED]	= System::Convert::ToDouble(RedTargetLVal->Text);

			Xtarget[GREEN]	= System::Convert::ToDouble(GreenTargetXVal->Text);
			Ytarget[GREEN]	= System::Convert::ToDouble(GreenTargetYVal->Text);
			Ltarget[GREEN]	= System::Convert::ToDouble(GreenTargetLVal->Text);
			
			Xtarget[BLUE]	= System::Convert::ToDouble(BlueTargetXVal->Text);
			Ytarget[BLUE]	= System::Convert::ToDouble(BlueTargetYVal->Text);
			Ltarget[BLUE]	= System::Convert::ToDouble(BlueTargetLVal->Text);

			double k = Ytarget[GREEN] * Ytarget[BLUE] * ( x - Xtarget[RED]);
			double n = Ytarget[RED] * Ytarget[BLUE] * (x - Xtarget[GREEN]);
			double p = Ytarget[RED] * Ytarget[GREEN] * (x - Xtarget[BLUE]);

			double q = Ytarget[GREEN] * Ytarget[BLUE] * (Ytarget[RED] - y);
			double v = Ytarget[RED] * Ytarget[BLUE] * (Ytarget[GREEN] - y);
			double w = Ytarget[RED] * Ytarget[GREEN] * (Ytarget[BLUE] - y);

			double p1 = (Lw * k * (w - q));
			double p2 = (Lw * q * (k - p));
			double p3 = (k - n) * (w - q);
			double p4 = (q - v) * (k - p);
			double Lgtarget = (p1 + p2) / (p3 + p4);
			if ((Lgtarget < 0.00001) && (Lgtarget > -0.00001))
			{
				Lgtarget = 0;
			}

			p1 = (Lw * k);
			p2 = (Lgtarget * (k - n));
			p3 = (k - p);
			double Lbtarget = (p1 - p2) / p3;
			if ((Lbtarget < 0.00001) && (Lbtarget > -0.00001))
			{
				Lbtarget = 0;
			}


			double Lrtarget = Lw - Lgtarget - Lbtarget;
			if ((Lrtarget < 0.00001) && (Lrtarget > -0.00001))
			{
				Lrtarget = 0;
			}

			R = Math::Pow((Lrtarget/Ltarget[RED]), 1.0 / GAtarget);
			G = Math::Pow((Lgtarget/Ltarget[GREEN]), 1.0 / GAtarget);
			B = Math::Pow((Lbtarget/Ltarget[BLUE]), 1.0 / GAtarget);

		}


		System::Void ApplyPointCorrection()
		{
			double x = 0;
			double y = 0;
			double Lw = 0;

			double Rin = System::Convert::ToDouble(RinVal->Text);
			double Gin = System::Convert::ToDouble(GinVal->Text);
			double Bin = System::Convert::ToDouble(BinVal->Text);

			double Rout = 0;
			double Gout = 0;
			double Bout = 0;

			CalcRGB2XY(Rin, Gin, Bin, x, y, Lw);
			double x1 = 0;
			double y1 = 0;
			double Lw1 = 0;
			TransfomXY2RGB(x, y, Lw, Rout, Gout, Bout);
			
			XInVal->Text = double(x).ToString();
			YInVal->Text = double(y).ToString();
			
			// display translated target point
			CalcTargetRGB2XY(Rin, Gin, Bin, x1, y1, Lw1);
			//CalcTargetRGB2XY(Rout, Gout, Bout, x, y, Lw);
			//AddDataPoint(resultGraph, x1, y1, Color::Blue);
			AddDataPointPair(resultGraph, x1, y1, x, y, Color::Red);

			XOutVal->Text = double(x1).ToString();
			YOutVal->Text = double(y1).ToString();


			RoutVal->Text = double(Rout).ToString();
			GoutVal->Text = double(Gout).ToString();
			BoutVal->Text = double(Bout).ToString();
		}

private:System::Void ApplyCCT_correction_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			ApplyPointCorrection();
		}

		System::Void ClearResGraph()
		{
			GraphPane ^myPane = resultGraph->GraphPane;
			myPane->CurveList->Clear();

			PointPairList ^list = gcnew PointPairList();
			list->Add( System::Convert::ToDouble(RedBaseXVal->Text), System::Convert::ToDouble(RedBaseYVal->Text) );
			list->Add( System::Convert::ToDouble(GreenBaseXVal->Text), System::Convert::ToDouble(GreenBaseYVal->Text) );
			list->Add( System::Convert::ToDouble(BlueBaseXVal->Text), System::Convert::ToDouble(BlueBaseYVal->Text) );
			list->Add( System::Convert::ToDouble(RedBaseXVal->Text), System::Convert::ToDouble(RedBaseYVal->Text) );
			// Generate a red curve with diamond symbols, and "Alpha" in the legend
			LineItem ^myCurve = myPane->AddCurve( L"", list, Color::Blue, SymbolType::Circle);
			// Fill the symbols with white
			myCurve->Symbol->Fill = gcnew Fill( Color::Blue );

			PointPairList ^listt = gcnew PointPairList();
			listt->Add( System::Convert::ToDouble(RedTargetXVal->Text), System::Convert::ToDouble(RedTargetYVal->Text) );
			listt->Add( System::Convert::ToDouble(GreenTargetXVal->Text), System::Convert::ToDouble(GreenTargetYVal->Text) );
			listt->Add( System::Convert::ToDouble(BlueTargetXVal->Text), System::Convert::ToDouble(BlueTargetYVal->Text) );
			listt->Add( System::Convert::ToDouble(RedTargetXVal->Text), System::Convert::ToDouble(RedTargetYVal->Text) );

			// Generate a red curve with diamond symbols, and "Alpha" in the legend
			LineItem ^myCurvet = myPane->AddCurve( L"", listt, Color::Red, SymbolType::Circle);
			// Fill the symbols with white
			myCurvet->Symbol->Fill = gcnew Fill( Color::Red );

			// Tell ZedGraph to calculate the axis ranges
			// Note that you MUST call this after enabling IsAutoScrollRange, since AxisChange() sets
			// up the proper scrolling parameters
			resultGraph->AxisChange();
			// Make sure the Graph gets redrawn
			resultGraph->Invalidate();
		}

private: System::Void ClearCalc_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 ClearResGraph();
		 }

		 System::Void DisplayResults(double Rin, double Gin, double Bin, double& Rout, double& Gout, double& Bout)
		 {
				double x1 = 0;
				double y1 = 0;
				double x2 = 0;
				double y2 = 0;
				double Lw1 =0;
				double Lw2 =0;

				bool ShowOrg = false;
				bool ShowRes = false;

				if (true == listShowResultsChBox->GetItemChecked(0))
				{
					ShowOrg = true;
				}
				if (true == listShowResultsChBox->GetItemChecked(1))
				{
					ShowRes = true;
				}

		 		CalcRGB2XY(Rin, Gin, Bin, x1, y1, Lw1);
				TransfomXY2RGB(x1, y1, Lw1, Rout, Gout, Bout);
				if (ShowOrg && ShowRes)
				{
					double x1 = 0;
					double y1 = 0;
					double Lw1 = 0;
					CalcTargetRGB2XY(Rin, Gin, Bin, x1, y1, Lw1);
					CalcTargetRGB2XY(Rout, Gout, Bout, x2, y2, Lw2);
					//AddDataPoint(resultGraph, x2, y2, Color::Blue);
					AddDataPointPair(resultGraph, x1, y1, x2, y2, Color::Green);
					
				}
				else if (ShowRes)
				{
					CalcTargetRGB2XY(Rout, Gout, Bout, x1, y1, Lw1);
					AddDataPoint(resultGraph, x1, y1, Color::Blue);
				}
				else if (ShowOrg)
				{
					double x1 = 0;
					double y1 = 0;
					double Lw1 = 0;
					CalcTargetRGB2XY(Rin, Gin, Bin, x1, y1, Lw1);
					AddDataPoint(resultGraph, x1, y1, Color::Red);
				}
		 }

		 System::Void ApplyBatchCorrection()
		 {
			double x = 0;
			double y = 0;
			double Lw = 0;
			double Rin = 0;
			double Gin = 0;
			double Bin = 0;

			double Rout = 0;
			double Gout = 0;
			double Bout = 0;

			int step = System::Convert::ToInt32(BatchStepTxtBox->Text);

			if (true == this->listBatchTestsChBox->GetItemChecked(0))
			{
				Rin = 0;
				Gin = 0;
				Bin = 0; 
				for (int i = 0; i < 255; i += step)
				{
					Rin = i;
					DisplayResults(Rin, Gin, Bin, Rout, Gout, Bout);
				}
			}

			if (true == this->listBatchTestsChBox->GetItemChecked(1))
			{
				Rin = 0;
				Gin = 0;
				Bin = 0; 
				for (int i = 0; i < 255; i += step)
				{
					Gin = i;
					DisplayResults(Rin, Gin, Bin, Rout, Gout, Bout);

				}
			}

			if (true == this->listBatchTestsChBox->GetItemChecked(2))
			{
				Rin = 0;
				Gin = 0;
				Bin = 0; 
				for (int i = 0; i < 255; i += step)
				{
					Bin = i;
					DisplayResults(Rin, Gin, Bin, Rout, Gout, Bout);

				}
			}

			if (true == this->listBatchTestsChBox->GetItemChecked(3))
			{
				Rin = 0;
				Gin = 128;
				Bin = 128; 
				for (int i = 0; i < 255; i += step)
				{
					Rin = i;
					DisplayResults(Rin, Gin, Bin, Rout, Gout, Bout);

				}
			}

			if (true == this->listBatchTestsChBox->GetItemChecked(4))
			{
				Rin = 128;
				Gin = 0;
				Bin = 128; 
				for (int i = 0; i < 255; i += step)
				{
					Gin = i;
					DisplayResults(Rin, Gin, Bin, Rout, Gout, Bout);

				}
			}

			if (true == this->listBatchTestsChBox->GetItemChecked(5))
			{
				Rin = 128;
				Gin = 128;
				Bin = 0; 
				for (int i = 0; i < 255; i += step)
				{
					Bin = i;

					DisplayResults(Rin, Gin, Bin, Rout, Gout, Bout);

				}
			}

			if (true == this->listBatchTestsChBox->GetItemChecked(6))
			{
				Rin = 0;
				Gin = 255;
				Bin = 255; 
				for (int i = 0; i < 255; i += step)
				{
					Rin = i;

					DisplayResults(Rin, Gin, Bin, Rout, Gout, Bout);


				}
			}

			if (true == this->listBatchTestsChBox->GetItemChecked(7))
			{
				Rin = 255;
				Gin = 0;
				Bin = 255; 
				for (int i = 0; i < 255; i += step)
				{
					Gin = i;
					DisplayResults(Rin, Gin, Bin, Rout, Gout, Bout);

				}
			}

			if (true == this->listBatchTestsChBox->GetItemChecked(8))
			{
				Rin = 255;
				Gin = 255;
				Bin = 0; 
				for (int i = 0; i < 255; i += step)
				{
					Bin = i;
					DisplayResults(Rin, Gin, Bin, Rout, Gout, Bout);

				}
			}

			if (true == this->listBatchTestsChBox->GetItemChecked(9))
			{
				Rin = 0;
				Gin = 0;
				Bin = 255; 
				for (int i = 0; i < 255; i += step)
				{
					Rin = i;
					Gin = i;

					DisplayResults(Rin, Gin, Bin, Rout, Gout, Bout);

				}
			}

			if (true == this->listBatchTestsChBox->GetItemChecked(10))
			{
				Rin = 255;
				Gin = 0;
				Bin = 0; 
				for (int i = 0; i < 255; i += step)
				{
					Bin = i;
					Gin = i;
					DisplayResults(Rin, Gin, Bin, Rout, Gout, Bout);

				}
			}

			if (true == this->listBatchTestsChBox->GetItemChecked(11))
			{
				Rin = 0;
				Gin = 255;
				Bin = 0; 
				for (int i = 0; i < 255; i += step)
				{
					Rin = i;
					Bin = i;
					DisplayResults(Rin, Gin, Bin, Rout, Gout, Bout);

				}
			}

			//R - range, G=0,B=255
			if (true == this->listBatchTestsChBox->GetItemChecked(12))
			{
				Rin = 0;
				Gin = 0;
				Bin = 255; 
				for (int i = 0; i < 255; i += step)
				{
					Rin = i;
					DisplayResults(Rin, Gin, Bin, Rout, Gout, Bout);

				}
			}

			//R - range, G=255,B=0
			if (true == this->listBatchTestsChBox->GetItemChecked(13))
			{
				Rin = 0;
				Gin = 255;
				Bin = 0; 
				for (int i = 0; i < 255; i += step)
				{
					Rin = i;
					DisplayResults(Rin, Gin, Bin, Rout, Gout, Bout);

				}
			}

			//G - range, R=0,B=255
			if (true == this->listBatchTestsChBox->GetItemChecked(14))
			{
				Rin = 0;
				Gin = 0;
				Bin = 255; 
				for (int i = 0; i < 255; i += step)
				{
					Gin = i;
					DisplayResults(Rin, Gin, Bin, Rout, Gout, Bout);


				}
			}

			//G - range, R=255,B=0
			if (true == this->listBatchTestsChBox->GetItemChecked(15))
			{
				Rin = 255;
				Gin = 0;
				Bin = 0; 
				for (int i = 0; i < 255; i += step)
				{
					Gin = i;
					DisplayResults(Rin, Gin, Bin, Rout, Gout, Bout);

				}
			}

			//B - range, R=0,G=255
			if (true == this->listBatchTestsChBox->GetItemChecked(16))
			{
				Rin = 0;
				Gin = 255;
				Bin = 0; 
				for (int i = 0; i < 255; i += step)
				{
					Bin = i;
					DisplayResults(Rin, Gin, Bin, Rout, Gout, Bout);

				}
			}

			//B - range, R=255,G=0
			if (true == this->listBatchTestsChBox->GetItemChecked(17))
			{
				Rin = 255;
				Gin = 0;
				Bin = 0; 
				for (int i = 0; i < 255; i += step)
				{
					Bin = i;

					DisplayResults(Rin, Gin, Bin, Rout, Gout, Bout);

				}
			}
		 
		 }

private: System::Void BatchCCT_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 ApplyBatchCorrection();
		 }

		 

private: System::Void TargetSelectCoordChB_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
		 {

		 }
private: System::Void BaseSelectCoordChB_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 
		 }


		 enum class MotionDirection
		 {
			UP = 0x1,
			DOWN = 0x2,
			LEFT = 0x4,
			RIGHT = 0x8,
			EXPAND = 0x10,
			COLLAPSE = 0x20,
			LUMPLUS  = 0x40,
			LUMMINUS = 0x80,
		 };

		 System::Void movePoints(MotionDirection direction)
		 {
			double stepMotion = System::Convert::ToDouble(stepTextBox->Text);

			
			if (TargetSelectCoordChB->Checked)
			{
				double XtargetR	= System::Convert::ToDouble(RedTargetXVal->Text);			
				double YtargetR	= System::Convert::ToDouble(RedTargetYVal->Text);	
				double LtargetR	= System::Convert::ToDouble(RedTargetLVal->Text);	
			
				double XtargetG	= System::Convert::ToDouble(GreenTargetXVal->Text);
				double YtargetG	= System::Convert::ToDouble(GreenTargetYVal->Text);
				double LtargetG	= System::Convert::ToDouble(GreenTargetLVal->Text);

				double XtargetB	= System::Convert::ToDouble(BlueTargetXVal->Text);	
				double YtargetB	= System::Convert::ToDouble(BlueTargetYVal->Text);	
				double LtargetB	= System::Convert::ToDouble(BlueTargetLVal->Text);	

				if (MotionDirection::UP == direction)
				{
					YtargetR += stepMotion;
					YtargetG += stepMotion;
					YtargetB += stepMotion;
				}

				if (MotionDirection::DOWN == direction)
				{
					YtargetR -= stepMotion;
					YtargetG -= stepMotion;
					YtargetB -= stepMotion;
				}

				if (MotionDirection::LEFT == direction)
				{
					XtargetR -= stepMotion;
					XtargetG -= stepMotion;
					XtargetB -= stepMotion;
				}

				if (MotionDirection::RIGHT == direction)
				{
					XtargetR += stepMotion;
					XtargetG += stepMotion;
					XtargetB += stepMotion;
				}

				if (MotionDirection::EXPAND == direction)
				{
					XtargetR += stepMotion;
					XtargetB -= stepMotion;

					YtargetG += stepMotion;
					YtargetB -= stepMotion;
				}

				if (MotionDirection::COLLAPSE == direction)
				{
					XtargetR -= stepMotion;
					XtargetB += stepMotion;

					YtargetG -= stepMotion;
					YtargetB += stepMotion;
				}

				if (MotionDirection::LUMPLUS == direction)
				{
					LtargetR += stepMotion*100;
					LtargetG += stepMotion*100;
					LtargetB += stepMotion*100;
				}

				if (MotionDirection::LUMMINUS == direction)
				{
					LtargetR -= stepMotion*100;
					LtargetG -= stepMotion*100;
					LtargetB -= stepMotion*100;
				}



				RedTargetXVal->Text = double(XtargetR).ToString();
				RedTargetYVal->Text= double(YtargetR).ToString();
				RedTargetLVal->Text= double(LtargetR).ToString();
				
				GreenTargetXVal->Text= double(XtargetG).ToString();
				GreenTargetYVal->Text= double(YtargetG).ToString();
				GreenTargetLVal->Text= double(LtargetG).ToString();
				
				BlueTargetXVal->Text= double(XtargetB).ToString();
				BlueTargetYVal->Text= double(YtargetB).ToString();
				BlueTargetLVal->Text= double(LtargetB).ToString();

			}
			if (BaseSelectCoordChB->Checked)				
			{
				double XbaseR	= System::Convert::ToDouble(RedBaseXVal->Text);			
				double YbaseR	= System::Convert::ToDouble(RedBaseYVal->Text);	
				double LbaseR	= System::Convert::ToDouble(RedBaseLVal->Text);
			
				double XbaseG= System::Convert::ToDouble(GreenBaseXVal->Text);
				double YbaseG= System::Convert::ToDouble(GreenBaseYVal->Text);
				double LbaseG= System::Convert::ToDouble(GreenBaseLVal->Text);

				double XbaseB = System::Convert::ToDouble(BlueBaseXVal->Text);	
				double YbaseB	= System::Convert::ToDouble(BlueBaseYVal->Text);	
				double LbaseB	= System::Convert::ToDouble(BlueBaseLVal->Text);

				if (MotionDirection::UP == direction)
				{
					YbaseR += stepMotion;
					YbaseG += stepMotion;
					YbaseB += stepMotion;
				}

				if (MotionDirection::DOWN == direction)
				{
					YbaseR -= stepMotion;
					YbaseG -= stepMotion;
					YbaseB -= stepMotion;
				}

				if (MotionDirection::LEFT == direction)
				{
					XbaseR -= stepMotion;
					XbaseG -= stepMotion;
					XbaseB -= stepMotion;
				}

				if (MotionDirection::RIGHT == direction)
				{
					XbaseR += stepMotion;
					XbaseG += stepMotion;
					XbaseB += stepMotion;
				}

				if (MotionDirection::EXPAND == direction)
				{
					XbaseR += stepMotion;
					XbaseB -= stepMotion;

					YbaseG += stepMotion;
					YbaseB -= stepMotion;
				}

				if (MotionDirection::COLLAPSE == direction)
				{
					XbaseR -= stepMotion;
					XbaseB += stepMotion;

					YbaseG -= stepMotion;
					YbaseB += stepMotion;
				
				}

				if (MotionDirection::LUMPLUS == direction)
				{
					LbaseR += stepMotion*100;
					LbaseG += stepMotion*100;
					LbaseB += stepMotion*100;
				}

				if (MotionDirection::LUMMINUS == direction)
				{
					LbaseR -= stepMotion*100;
					LbaseG -= stepMotion*100;
					LbaseB -= stepMotion*100;
				}


				RedBaseXVal->Text = double(XbaseR).ToString();
				RedBaseYVal->Text = double(YbaseR).ToString();
				RedBaseLVal->Text = double(LbaseR).ToString();
				
				GreenBaseXVal->Text = double(XbaseG).ToString();
				GreenBaseYVal->Text = double(YbaseG).ToString();
				GreenBaseLVal->Text = double(LbaseG).ToString();
				
				BlueBaseXVal->Text = double(XbaseB).ToString();
				BlueBaseYVal->Text = double(YbaseB).ToString();
				BlueBaseLVal->Text = double(LbaseB).ToString();
			}

			RefreshGraphs();
		 }

private: System::Void MoveUpBtn_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 movePoints(MotionDirection::UP);
		 }
private: System::Void MoveRightBtn_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 movePoints(MotionDirection::RIGHT);
		 }
private: System::Void MoveDownBtn_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 movePoints(MotionDirection::DOWN);
		 }
private: System::Void MoveLeftBtn_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 movePoints(MotionDirection::LEFT);
		 }
private: System::Void ExpandBtn_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 movePoints(MotionDirection::EXPAND);
		 }
private: System::Void CollapseBtn_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 movePoints(MotionDirection::COLLAPSE);
		 }
private: System::Void LumPlusBtn_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 movePoints(MotionDirection::LUMPLUS);
		 }
private: System::Void LumMinusBtn_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 movePoints(MotionDirection::LUMMINUS);
		 }
private: System::Void GABaseVal_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 RefreshGraphs();
		 }
private: System::Void RedTargetXVal_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 RefreshGraphs();
		 }
private: System::Void GreenTargetXVal_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 RefreshGraphs();
		 }
private: System::Void BlueTargetXVal_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 RefreshGraphs();
		 }
private: System::Void WhiteTargetXVal_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 RefreshGraphs();
		 }
private: System::Void RedTargetYVal_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 RefreshGraphs();
		 }
private: System::Void GreenTargetYVal_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 RefreshGraphs();
		 }
private: System::Void BlueTargetYVal_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 RefreshGraphs();
		 }
private: System::Void WhiteTargetYVal_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 RefreshGraphs();
		 }
private: System::Void GATargetVal_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 RefreshGraphs();
		 }
private: System::Void RedTargetLVal_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 RefreshGraphs();
		 }
private: System::Void GreenTargetLVal_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 RefreshGraphs();
		 }
private: System::Void BlueTargetLVal_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 RefreshGraphs();
		 }
private: System::Void WhiteTargetLVal_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 RefreshGraphs();
		 }
private: System::Void RedBaseXVal_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 RefreshGraphs();
		 }
private: System::Void RedBaseYVal_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 RefreshGraphs();
		 }
private: System::Void RedBaseLVal_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 RefreshGraphs();
		 }
private: System::Void GreenBaseXVal_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 RefreshGraphs();
		 }
private: System::Void GreenBaseYVal_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 RefreshGraphs();
		 }
private: System::Void GreenBaseLVal_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 RefreshGraphs();
		 }
private: System::Void BlueBaseXVal_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 RefreshGraphs();
		 }
private: System::Void BlueBaseYVal_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 RefreshGraphs();
		 }
private: System::Void BlueBaseLVal_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 RefreshGraphs();
		 }
private: System::Void WhiteBaseXVal_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 RefreshGraphs();
		 }
private: System::Void WhiteBaseYVal_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 RefreshGraphs();
		 }
private: System::Void WhiteBaseLVal_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 RefreshGraphs();
		 }
private: System::Void RinVal_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 RefreshGraphs();
		 }
private: System::Void GinVal_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 RefreshGraphs();
		 }
private: System::Void BinVal_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 RefreshGraphs();
		 }
private: System::Void RoutVal_TextChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 double val = System::Convert::ToDouble(RoutVal->Text);
			 if ((val > System::Convert::ToDouble(RinVal->Maximum)) || 
				 (val < System::Convert::ToDouble(RinVal->Minimum)))
			 {
				 RoutLbl->ForeColor = Color::Red;
				 //RoutLbl->Font.Bold = true;
			 }
			 else
			 {
				RoutLbl->ForeColor = Color::Black;
			 }

		 }
private: System::Void GoutVal_TextChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 double val = System::Convert::ToDouble(GoutVal->Text);
			 if ((val > System::Convert::ToDouble(GinVal->Maximum)) || 
				 (val < System::Convert::ToDouble(GinVal->Minimum)))
			 {
				 GoutLbl->ForeColor = Color::Red;
				 //RoutLbl->Font.Bold = true;
			 }
			 else
			 {
				GoutLbl->ForeColor = Color::Black;
			 }
		 }
private: System::Void BoutVal_TextChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 double val = System::Convert::ToDouble(BoutVal->Text);
			 if ((val > System::Convert::ToDouble(BinVal->Maximum)) || 
				 (val < System::Convert::ToDouble(BinVal->Minimum)))
			 {
				 BoutLbl->ForeColor = Color::Red;
				 //RoutLbl->Font.Bold = true;
			 }
			 else
			 {
				BoutLbl->ForeColor = Color::Black;
			 }
		 }
};
}
