object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 546
  ClientWidth = 1044
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Slika: TImage
    Left = 8
    Top = 24
    Width = 857
    Height = 457
    OnMouseDown = SlikaMouseDown
    OnMouseMove = SlikaMouseMove
  end
  object LabelBrojTacaka: TLabel
    Left = 885
    Top = 24
    Width = 61
    Height = 15
    Caption = 'Broj ta'#269'aka:'
  end
  object LabelPoluprecnik: TLabel
    Left = 885
    Top = 171
    Width = 66
    Height = 15
    Caption = 'Polupre'#269'nik:'
  end
  object DugmeOcisti: TButton
    Left = 885
    Top = 512
    Width = 132
    Height = 25
    Caption = 'O'#269'isti'
    TabOrder = 0
    OnClick = DugmeOcistiClick
  end
  object InputBrojTacakaRandom: TEdit
    Left = 885
    Top = 56
    Width = 138
    Height = 23
    TabOrder = 1
    Text = '20'
  end
  object DugmeGenerisiRandomTacke: TButton
    Left = 885
    Top = 96
    Width = 132
    Height = 25
    Caption = 'Generi'#353'i random ta'#269'ke'
    TabOrder = 2
    OnClick = DugmeGenerisiRandomTackeClick
  end
  object TextKoordinate: TEdit
    Left = 885
    Top = 472
    Width = 132
    Height = 23
    TabOrder = 3
  end
  object InputPoluprecnik: TEdit
    Left = 885
    Top = 208
    Width = 138
    Height = 23
    TabOrder = 4
    Text = '100'
  end
  object DugmeOptimalnaKruznicaBrzo: TButton
    Left = 8
    Top = 512
    Width = 161
    Height = 25
    Caption = 'Optimalna kru'#382'nica'
    TabOrder = 5
    OnClick = DugmeOptimalnaKruznicaBrzoClick
  end
end
