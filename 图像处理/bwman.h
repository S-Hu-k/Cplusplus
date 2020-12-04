#pragma once
//---------------------------------------------------------------------------

#ifndef bwMainH
#define bwMainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>

#define	USE_GDIPLUS

#include "BmpData.h"
//---------------------------------------------------------------------------
enum TLockType { ltEdit, ltTrack };
typedef Set<TLockType, ltEdit, ltTrack> TLockTypes;

class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TPaintBox* PaintBox1;
	TLabel* Label1;
	TLabel* Label2;
	TLabel* Label3;
	TLabel* Label4;
	TLabel* Label5;
	TLabel* Label6;
	TLabel* Label7;
	TLabel* Label8;
	TLabel* Label9;
	TLabel* Label10;
	TLabel* Label11;
	TLabel* Label12;
	TLabel* Label13;
	TLabel* Label18;
	TComboBox* ComboBox1;
	TEdit* Edit1;
	TTrackBar* TrackBar1;
	TEdit* Edit2;
	TTrackBar* TrackBar2;
	TEdit* Edit3;
	TTrackBar* TrackBar3;
	TEdit* Edit4;
	TTrackBar* TrackBar4;
	TEdit* Edit5;
	TTrackBar* TrackBar5;
	TEdit* Edit6;
	TTrackBar* TrackBar6;
	TCheckBox* CheckBox1;
	TGroupBox* GroupBox1;
	TLabel* Label14;
	TLabel* Label15;
	TLabel* Label16;
	TLabel* Label17;
	TPaintBox* PaintBox2;
	TEdit* Edit7;
	TTrackBar* TrackBar7;
	TEdit* Edit8;
	TTrackBar* TrackBar8;
	TColorDialog* ColorDialog1;
	void __fastcall FormCreate(TObject* Sender);
	void __fastcall FormDestroy(TObject* Sender);
	void __fastcall ComboBox1Change(TObject* Sender);
	void __fastcall TrackBar1Change(TObject* Sender);
	void __fastcall Edit1Change(TObject* Sender);
	void __fastcall Edit1KeyPress(TObject* Sender, char& Key);
	void __fastcall Edit1Exit(TObject* Sender);
	void __fastcall CheckBox1Click(TObject* Sender);
	void __fastcall TrackBar7Change(TObject* Sender);
	void __fastcall Edit7Change(TObject* Sender);
	void __fastcall Edit7KeyPress(TObject* Sender, char& Key);
	void __fastcall PaintBox2Click(TObject* Sender);
	void __fastcall PaintBox1Paint(TObject* Sender);
	void __fastcall PaintBox2Paint(TObject* Sender);
	void __fastcall TrackBar8Change(TObject* Sender);
private:	// User declarations
	Bitmap* Source;					// Դͼ��
	Bitmap* Dest;					// �������ͼ��
	BitmapData srcData;
	BitmapData dstData;
	float bwColors[6];				// �Ҷ�ѡ������
	int Bright;						// ����
	TTrackBar* TrackBars[6];		// �Ҷ�ѡ����Ԫ������
	TEdit* Edits[6];				// �Ҷ�ѡ��༭������
	TLockTypes Lock;
	Gdiplus::Rect rect;
	ARGBQuad MixColor;				// �����ɫ

	int __fastcall GetHue(void);
	int __fastcall GetSat(void);
	void __fastcall SetHue(int hue);
	void __fastcall SetSat(int sat);

	void __fastcall MixColorToHSV(void);
	void __fastcall HSVToMixColor(void);
	void __fastcall Execute(void);
	void __fastcall MixColorChange(void);
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);

	__property int Hue = { read = GetHue, write = SetHue };	// ɫ��
	__property int Sat = { read = GetSat, write = SetSat };	// ���Ͷ�
};
//---------------------------------------------------------------------------
const CustomIndex = 11;				// �Զ���ѡ������
const DefaultTint = 0xe1d3b3;		// ȱʡ�����ɫ
const int DefOptions[][6] =			// Ԥ����Ҷ�ѡ��
{
	{40, 60, 40, 60, 20, 80},
	{128, 128, 100, 100, 128, 100},
	{100, 100, 100, 100, 100, 100},
	{0, 0, 0, 0, 0, 0},
	{-40, 235, 144, -68, -3, -107},
	{120, 110, -10, -50, 0, 120},
	{50, 120, 90, 50, 0, 0},
	{0, 0, 0, 110, 110, 110},
	{120, 120, -10, -50, -50, 120},
	{-50, -50, -50, 150, 150, 150},
	{120, 110, 40, -30, 0, 70}
};

extern PACKAGE TForm1* Form1;
//---------------------------------------------------------------------------
#endif