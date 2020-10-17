/*
G:\TOOL\prism.exe -convert "C:\Users\Administrator\Downloads\����UCC_�̽��͸�_���Ǳ⸻���_1������.mp4" -format .3gp MPEG4 128 256 320 240 AMR 10 -hide
*/

//{
	/*
	Using the Prism Command-line Tool
Contents | Previous | Next  Prism Video File Converter
Help v 2.63 
 


The Prism command-line tool allows you to convert files from the command line. This can be used to let other software convert files using Prism or to automate batch conversion.

Important Note: Due to a limitation in the way Windows handles running graphical programs from the command line, Prism cannot give any feedback when an issued command has been completed, nor can it block the command line while a conversion is taking place. We are currently investigating possible ways to circumvent the Windows problem, but please note it down for now and take it into account when issuing command-line orders to Prism. 

The Prism executable is usually located as "C:\Program Files\NCH Software\Prism\prism.exe"

Usage: prism.exe [options] [files to add] 

"Options" is where you can issue a series of commands to Prism. The options are: 

-convert - convert all files loaded into Prism. 

-clear - remove all files loaded into Prism. 

-addfolder [FOLDER_NAME] - add a folder of files into Prism. 

-format [FORMAT_NAME] - specify the output file format for which to convert the loaded files. Possible format names include: 

3gp
asf
avi
dv
flv
gif
mkv
mov
mp4
m4v
mpg
ogv
rm
swf
webm
wmv
divx
xvid
amv
jpg
png
"Android 480P"
"Android 720P"
"iPhone 2G"
"iPhone 3G"
"iPhone 3GS"
"iPhone 4"
"iPhone 4S"
"iPhone 5/5c"
"iPhone 5s/6/6P"
iPhone 6s/6sP
iPod Classic
"iPod Touch 1"
"iPod Touch 2"
"iPod Touch 3"
"iPod Touch 4"
"iPod Touch 5"
"iPad 1"
"iPad 2"
"iPad 3"
"iPad 4"
"iPad Air"
"iPad Air2"
"iPad Mini"
"iPad Mini2/3"
"iPad Mini4"
"PSP"
"PS Vita"
"PS3"
"Xbox 360"
mp3
wav

-outfolder [FOLDER_NAME] - specify the output folder to store the converted files. Do NOT end the folder path with a backslash '\' character. 

-overwrite [OVERWRITE_FLAG] - specifies what to do when the converted file already exists. The flags are "PROMPT" (Prompt for What to Do), "ALWAYS" (Overwrite the File), "NEVER" (Don't Convert the Original File), "CANCEL" (Abort All Conversions), "APPENDNUMBER [format]" (Append number to filename - [format] is optional, if blank it will use the format already specified in the program). 

-settings [FORMAT_NAME] [SETTINGS_OPTIONS] - specifies the settings configuration to use for the specified format. For more detail on what parameters to use, see further down the page. 

-edit [RESIZE_TYPE] [WIDTH] [HEIGHT] [FRAMERATE] - specifies the video output options. RESIZE_TYPE - either "NONE", "CROP" or "LETTERBOX". WIDTH and HEIGHT - desired dimensions of the video. FRAMERATE - desired video frame rate (or zero if no frame rate conversion is required). 

-hide - hide the Prism window. 

-show - show the Prism window. 

-exit - exit Prism. 

"Files to Add" is where you type in the files you want to load into Prism. All typed filenames must use the full filepath of the name, and circumfixed with inverted commas. 

Examples: 

prism.exe -format .mp4

prism.exe -format "iPhone 4"

prism.exe -outfolder "C:\My Videos";

prism.exe -hide

prism.exe "C:\My Documents\video.avi"

prism.exe -convert "C:\My Videos\video.avi" -format .mp4 -overwrite ALWAYS

prism.exe -convert "C:\My Videos\video.flv" -format .mpg -overwrite APPENDNUMBER "%filename%-%number%"

prism.exe -convert "DVD:C:\My Videos\Flying Daggers" -settings .mp4 iPod 512 768 23 -overwrite APPENDNUMBER "%filename%-%number%"

prism.exe -convert "DVD:C:\My Videos\Flying Daggers" -format "iPhone 4S" -settings .mp4 H264 512 768 23 -overwrite APPENDNUMBER "%filename%-%number%"

Unless you are in the Prism folder you will need to replace "prism.exe" from above with the full path "C:\Program Files\NCH Software\Prism\prism.exe" like this:

"C:\Program Files\NCH Software\Prism\prism.exe" -convert "C:\My Videos\video.avi" -format .mp4

Settings Options: 

The following details what parameters to enter when using the "-settings" options. Note the order in which the parameters are written is the order in which they must be typed. Additionally, all parameters must be entered, otherwise the command will not take effect.

Note the possible combination of values that can be entered depend largely on the codec, so you need to open Prism and determine beforehand what values you can use for the codec in question.

Also note that when converting for preset devices, mp4 is the only supported output format, so please always use .mp4 to set preset device settings.

.avi [VIDEO_ENCODER] [AVERAGE_BITRATE] [MAXIMUM_BITRATE] [QUALITY_RATEFACTOR] [SAMPLE_RATE] [CHANNELS] [SOUND_BITRATE] 

VIDEO_ENCODER - either "MPEG4", "H264", "DVPAL" or "DVNTSC"
AVERAGE_BITRATE - average bitrate in kbits per sec (ignored when using H264 or DV)
MAXIMUM_BITRATE - maximum bitrate in kbits per sec (ignored when using H264 or DV)
QUALITY_RATEFACTOR - quality (ratefactor) in the range 51.0 to 1.0 (only used by H264)
SAMPLE_RATE - entered in Hz e.g. 8000
CHANNELS - either 1 or 2
SOUND_BITRATE - sound bitrate in kbits per sec (ignored when using DV)
Examples: 

-settings .avi MPEG4 768 1000 0.0 44100 2 128
-settings .avi DVPAL 0 0 0.0 48000 2 0
-settings .avi H264 0 0 24.0 48000 2 256

.wmv and .asf [VIDEO_ENCODER] [VIDEO_BITRATE] [SOUND_ENCODER_INDEX] [SAMPLE_RATE] [CHANNELS] [SOUND_BITRATE] 

VIDEO_ENCODER - either "WMV8" or "WMV9"
VIDEO_BITRATE - video bitrate in kbits per sec
SOUND_ENCODER_INDEX - zero based index of the sound encoder
SAMPLE_RATE - entered in Hz e.g. 48000
CHANNELS - either 1 or 2
SOUND_BITRATE - sound bitrate in kbits per sec
Examples: 

-settings .wmv WMV8 512 1 32000 2 32
-settings .asf WMV9 1024 2 44100 2 48

.mpg [VIDEO_ENCODER] [AVERAGE_BITRATE] [MAXIMUM_BITRATE] [SAMPLE_RATE] [SOUND_BITRATE] 

VIDEO_ENCODER - either "MPEG2" or "MPEG1"
AVERAGE_BITRATE - average bitrate in kbits per sec
MAXIMUM_BITRATE - maximum bitrate in kbits per sec
SAMPLE_RATE - entered in Hz e.g. 44100
SOUND_BITRATE - sound bitrate in kbits per sec
Examples: 

-settings .mpg MPEG2 4000 9000 44100 128

.3gp [VIDEO_ENCODER] [AVERAGE_BITRATE] [MAXIMUM_BITRATE] [WIDTH] [HEIGHT] [SOUND_ENCODER] [SOUND_BITRATE] 

VIDEO_ENCODER - either "H263" or "MPEG4"
AVERAGE_BITRATE - average bitrate in kbits per sec
MAXIMUM_BITRATE - maximum bitrate in kbits per sec
WIDTH - desired width of the video (ignored when using MPEG4)
HEIGHT - desired height of the video (ignored when using MPEG4)
SOUND_ENCODER - either "AMR" or "AAC"
SOUND_BITRATE - sound bitrate in kbits per sec
Examples: 

-settings .3gp H263 128 256 176 144 AMR 7.40
-settings .3gp MPEG4 768 1000 0 0 AAC 64

.mp4 [VIDEO_ENCODER] [AVERAGE_BITRATE] [MAXIMUM_BITRATE] [QUALITY_RATEFACTOR] [SOUND_BITRATE] 

VIDEO_ENCODER - either "H264", "MPEG4" or "PSP" (if converting for preset devices, do not use "MPEG4")
AVERAGE_BITRATE - average bitrate in kbits per sec (ignored if H264 or PSP)
MAXIMUM_BITRATE - maximum bitrate in kbits per sec (ignored if H264 or PSP)
QUALITY_RATEFACTOR - quality (ratefactor) in the range 51.0 to 1.0 (ignored if MPEG4)
SOUND_BITRATE - sound bitrate in kbits per sec
Examples: 

-settings .mp4 H264 0 0 23.0 32
-settings .mp4 MPEG4 768 1000 0.0 64
-settings .mp4 PSP 0 0 18.5 112

.mov [QUALITY_RATEFACTOR] [SOUND_BITRATE] 

QUALITY_RATEFACTOR - Quality (ratefactor) in the range 51.0 to 1.0
SOUND_BITRATE - sound bitrate in kbits per sec
Examples: 

-settings .mov 23.0 128
-settings .mov 30.6 64

.flv [VIDEO_ENCODER] [AVERAGE_BITRATE] [MAXIMUM_BITRATE] [QUALITY_RATEFACTOR] [SOUND_BITRATE] 

VIDEO_ENCODER - either "H264" or "FLV1"
AVERAGE_BITRATE - average bitrate in kbits per sec (ignored if H264)
MAXIMUM_BITRATE - maximum bitrate in kbits per sec (ignored if H264)
QUALITY_RATEFACTOR - quality (ratefactor) in the range 51.0 to 1.0 (ignored if FLV1)
SOUND_BITRATE - sound bitrate in kbits per sec
Examples: 

-settings .flv FLV1 128 256 0.0 32
-settings .flv H264 0 0 21.0 64

 
 
Using the Prism Command-line Tool 
Contents | Previous | Next  �� NCH Software
NCH Software  
 

	*/
	/*
	Prism ����� ������, ����ٿ��� ����� ������ ��ȯ�� �� �ְ� ���ݴϴ�. �̰��� �ٸ� ����Ʈ��� Prism���� ������ ��ȯ�ϰų� �ڵ� �ϰ� ��ȯ�� �ϴµ� �̿�� �� �ֽ��ϴ�.

���� ����: �����찡 ����ٿ��� �׷��� ���α׷� �����ϴ� ��Ŀ� ���� �Ѱ� ������, Prism�� �̹� ����� ���� ����� ���Ͽ� ���ؼ��� �ǵ���� ������ �� ����, ���� ��ȯ�� ���۵� ������ ������� ������ �� �����ϴ�. ����� ���� �̷� �����쿡���� ������ �����ϱ� ���� ��� ���̴�, ���� Prism���� ������� �����Ͻ� �� �̷� ���� �����Ͻñ� �ٶ��ϴ�. 

Prism ���� ���α׷��� ���� "C:\Program Files\NCH Software\Prism\prism.exe"�� ��ġ�� �ֽ��ϴ�.

��뷮: prism.exe [�ɼ�] [�߰��� ����] 

"�ɼ�" �� Prism�� �Ϸ��� ��ɵ��� ���� �� �ִ� ���Դϴ�. �ɼǵ��� ������ �����ϴ�: 

- ��ȯ -Prism���� ������ ��� ������ ��ȯ 

-���� - Prism���� ������ ��� ������ ���� 

-���� �߰� [����_�̸�] Prism�� ������ ��� ���� �߰� 

-���� [����_�̸�] -�ҷ��� ������ ��ȯ�ϴµ� ����� ��� ���� ������ �����ϼ���. ��� ������ ���ĸ��� ������ �����ϴ�: 

avi
wmv
asf
mpg
3gp
mp4
mov
flv
swf
ogv
webm
rm
gif
dv
mkv
jpg
png
"�ص���̵� 480P"
"�ص���̵� 720P"
"iPhone 2G"
"iPhone 3G"
"iPhone 3G"
"iPhone 4"
"iPhone 4S"
"iPhone 5/5c"
"iPhone 5s/6/6P"
iPhone 6s/6sP
iPod Classic
"iPod Touch 1"
"iPod Touch 2"
"iPod Touch 3"
"iPod Touch 4"
"iPod Touch 5"
"iPad 1"
"iPad 2"
"iPad 3"
"iPad 4"
"iPad Air"
"iPad Air2"
"iPad Mini"
"iPad Mini2/3"
"iPad Mini4"
"PSP"
"PS Vita"
"PS3"
"Xbox 360"
mp3
wav

-��� ���� [����_�̸�] -��ȯ�� ������ ������ ��� ������ �����ϼ���. ���� ��θ� �齽���� ���� '\'�� ������ ���ʽÿ�. 

-����� [�����_ǥ��] -��ȯ�� ������ �̹� ������ �� ������ ���� �����մϴ�. ǥ�õ��� "�˸�T" (������ ���� �˸�), "�׻� �����" (���� �����), "���� ��ȯ���� �ʱ�" (���������� ��ȯ���� ����), "���" (��ȯ�� ��� ����), "��ȣ÷��[����]" (�����̸��� ��ȣ ÷�� - [����]�� �ΰ����� ������, �ƹ� ǥ�õ� ���� ��� ���α׷����� �̹� ������ ������ ����� ���Դϴ�. 

-���� [����_�̸�] [����_�ɼ�] -��õ� �������� ����ϱ����� ���� ������ �����մϴ�. � �Ķ���͸� ����ؾ� �ϴ����� ���� �� �ڼ��� ������ ������ �Ʒ� �� �������� �����ϼ���. 

-���� [ũ�� ����_����] [����] [����] [��������] -���� ��� �ɼ��� ���� ũ�� ����_����- "�״�� �α�", "�߶󳻱�" �� "���͹ڽ�". ���̿� ���� - ������ ���ϴ� ũ�� �������� -���ϴ� ���� ������ ���� (������ ���� ��ȯ�� �ʿ���� ���� 0). 

-����� - Prism â�� ����ϴ�. 

-�����ֱ� - Prism â�� �����ݴϴ�. 

-���� - Prism ���� 

"���� �߰�" �� Prism�� �������� ���ϴ� ���Ͽ� �ۼ��ϴ� ���Դϴ�. �Է��Ͻ� ��� ���� �̸����� �� �̸��� ��ü ��θ� ����ؾ��ϰ� " (����ǥ)�� �־���մϴ�. 

��: 

prism.exe -���� .mp4

prism.exe -����"iPhone 4"

prism.exe -��� ���� "C:\My Videos";

prism.exe -�����

prism.exe "C:\My Documents\video.avi"

prism.exe -��ȯ "C:\My Videos\video.avi" -���� .mp4 -�׻� �����

prism.exe -��ȯ "C:\My Videos\video.flv" -���� .mpg -����� ��ȣ�߰� "%filename%-%number%"

prism.exe -��ȯ "DVD:C:\My Videos\Flying Daggers" -���� .mp4 iPod 512 768 23 -����� ��ȣ�߰� "%filename%-%number%"

prism.exe -��ȯ "DVD:C:\My Videos\Flying Daggers" -���� "iPhone 4S" -���� .mp4 H264 512 768 23 -����� ��ȣ�߰� "%filename%-%number%"

����� Prism ���� �ȿ� ���� �ʴ� ��, ���� "prism.exe" ��, ��ü ��� "C:\Program Files\NCH Software\Prism\prism.exe"�� �Բ� �̷��� ��ü�ؾ� �մϴ�.:

"C:\Program Files\NCH Software\Prism\prism.exe" -��ȯ "C:\My Videos\video.avi" -���� .mp4

���� �ɼ�: 

�Ʒ��� "-����" �ɼ��� ���� � �Ķ���͸� �Է��ؾ� �ϴ����� ���� ���� �����Դϴ�. �Ķ���Ͱ� ������ ������� �װ͵��� �Է��ؾ� ���� �����ϼ���. �߰�������, �Ķ���͵��� ���� �� �Է��ϼž� �մϴ�. �׷��� ���� ������ ��� ������ ��ȿ�մϴ�.

�Է��� �� �ִ� ������ ������ ���� �ַ� �ڵ��� �¿���� �����ϼ���. �׷��Ƿ� Prism�� ���� �Ŀ� � ������ �ڵ��� ����� �������� �̸� �����ؾ��մϴ�.

������ ��ġ�� ���� ��ȯ�� ��, ���� mp4 ���� �����Ǵ� ��� �������� �����Ͻð�, ������ ��ġ ������ �ϽǶ� �׻� .mp4�� ����ϼ���.

.avi [����_���ڴ�] [���_��Ʈ����Ʈ] [�ִ�_��Ʈ����Ʈ] [ǰ��_�� ���] [����_����Ʈ] [ä��] [����_��Ʈ����Ʈ] 

����_���ڴ� - "MPEG4", "H264", "DVPAL" �� "DVNTSC"
��ա���Ʈ����Ʈ - �ʴ� kbits�� ��� ��Ʈ����Ʈ (H264 �� DV ���ÿ� ������� ����)
�ִ롩��Ʈ����Ʈ - �ʴ� kbits�� �ִ� ��Ʈ����Ʈ (H264 �� DV ���ÿ� ������� ����)
ǰ��_ �� ��� - 51.0 ���� 1.0������ ǰ�� �� ��� (H264 ���ÿ��� ����)
����_����Ʈ - Hz�� �Է� (��:8000)
ä�� - 1 �̳� 2
���塩��Ʈ����Ʈ - �ʴ� kbits�� ���� ��Ʈ����Ʈ (DV ���ÿ� ������� ����)
��: 

-���� .avi MPEG4 768 1000 0.0 44100 2 128
-���� .avi DVPAL 0 0 0.0 48000 2 0
-���� .avi DVPAL 0 0 0.0 48000 2 0

.wmv �� .asf [����_���ڴ�] [����_��Ʈ����Ʈ] [����_���ڴ�_����] [����_����Ʈ] [ä��] [����_��Ʈ����Ʈ] 

����_���ڴ� - "WMV8" �� "WMV9"
����_��Ʈ����Ʈ - �ʴ� kbits�� ���� ��Ʈ����Ʈ
����_���ڴ�_���� - ���� ���̽� ������ ���� ���ڴ�
����_����Ʈ - Hz�� �Է� (��:48000)
ä�� - 1 �̳� 2
����_��Ʈ����Ʈ - �ʴ� kbits�� ���� ��Ʈ����Ʈ
��: 

-���� .wmv WMV8 512 1 32000 2 32
-���� .asf WMV9 1024 2 44100 2 48

.mpg [����_���ڴ�] [���_��Ʈ����Ʈ] [�ִ�_��Ʈ����Ʈ][����_����Ʈ] [����_��Ʈ����Ʈ] 

����_���ڴ� - "MPEG2" �� "MPEG1"
���_��Ʈ����Ʈ - �ʴ� kbits�� ��� ��Ʈ����Ʈ
�ִ�_��Ʈ����Ʈ - �ʴ� kbits�� �ִ� ��Ʈ����Ʈ
����_����Ʈ - Hz�� �Է� (��:44100)
����_��Ʈ����Ʈ - �ʴ� kbits�� ���� ��Ʈ����Ʈ
��: 

-���� .mpg MPEG2 4000 9000 44100 128

.3gp [����_���ڴ�] [���_��Ʈ����Ʈ] [�ִ�_��Ʈ����Ʈ] [����] [����] [����_���ڴ�] [����_��Ʈ����Ʈ] 

����_���ڴ� - "H263" �� "MPEG4"
���_��Ʈ����Ʈ - �ʴ� kbits�� ��� ��Ʈ����Ʈ
�ִ�_��Ʈ����Ʈ - �ʴ� kbits�� �ִ� ��Ʈ����Ʈ
���� - ���ϴ� ������ ���� (MPEG4 ���ÿ� ������� ����)
���� - ���ϴ� ������ ���� (MPEG4 ���ÿ� ������� ����)
����_���ڴ� - "AMR" �� "AAC"
����_��Ʈ����Ʈ - �ʴ� kbits�� ���� ��Ʈ����Ʈ
��: 

-���� .3gp H263 128 256 176 144 AMR 7.40
-���� .3gp MPEG4 768 1000 0 0 AAC 64

.mp4 [����_���ڴ�] [���_��Ʈ����Ʈ] [�ִ�_��Ʈ����Ʈ][ǰ��_�� ���] [����_��Ʈ����Ʈ] 

����_���ڴ� - "H264", "MPEG4" �� "PSP" (������ ��ġ�� ���� ��ȯ��, "MPEG4"�� ������� ������.)
��ա���Ʈ����Ʈ - �ʴ� kbits�� ��� ��Ʈ����Ʈ (H264 �� PSP ���ÿ� ������� ����)
�ִ롩��Ʈ����Ʈ - �ʴ� kbits�� �ִ� ��Ʈ����Ʈ (H264 �� PSP ���ÿ� ������� ����)
ǰ��_ �� ��� - 51.0 ���� 1.0������ ǰ�� �� ��� (MPEG4 ���ÿ� ������� ����)
����_��Ʈ����Ʈ - �ʴ� kbits�� ���� ��Ʈ����Ʈ
��: 

-���� .mp4 H264 0 0 23.0 32
-���� .mp4 MPEG4 768 1000 0.0 64
-���� .mp4 PSP 0 0 18.5 112

.mov [ǰ��_�� ���] [����_��Ʈ����Ʈ] 

ǰ��_ �� ��� - 51.0 ���� 1.0������ ǰ�� �� ���
����_��Ʈ����Ʈ - �ʴ� kbits�� ���� ��Ʈ����Ʈ
��: 

-���� .mov 23.0 128
-���� .mov 30.6 64

.flv [����_���ڴ�] [���_��Ʈ����Ʈ] [�ִ�_��Ʈ����Ʈ][ǰ��_�� ���] [����_��Ʈ����Ʈ] 

����_���ڴ� - "H264" �� "FLV1"
��ա���Ʈ����Ʈ - �ʴ� kbits�� ��� ��Ʈ����Ʈ (H264 ���ÿ� ������� ����)
�ִ롩��Ʈ����Ʈ - �ʴ� kbits�� �ִ� ��Ʈ����Ʈ (H264 ���ÿ� ������� ����)
ǰ��_ �� ��� - 51.0 ���� 1.0������ ǰ�� �� ��� (FLV �϶��� ������� ����)
����_��Ʈ����Ʈ - �ʴ� kbits�� ���� ��Ʈ����Ʈ
��: 

-���� .flv FLV1 128 256 0.0 32
-���� .flv H264 0 0 21.0 64
*/
//}
 /*

LRESULT CALLBACK WndProc(HWND hWnd,UINT iMessage,WPARAM wParam,LPARAM lParam)

{

     HDC hdc;

     PAINTSTRUCT ps;

     TCHAR *Mes="B:��Ʈ�� �б�, P:PNG�� ����, J:Jpeg�� ����, 1~5:�Ķ���� ��� ���";

     OPENFILENAME OFN;

     TCHAR lpstrFile[MAX_PATH]="";

 

     switch(iMessage) {

     case WM_CREATE:

          hWndMain=hWnd;

          return 0;

     case WM_KEYDOWN:

          switch (wParam) {

          case 'B':

              memset(&OFN, 0, sizeof(OPENFILENAME));

              OFN.lStructSize = sizeof(OPENFILENAME);

              OFN.hwndOwner=hWnd;

              OFN.lpstrFilter="��Ʈ�� ����(*.BMP)\0*.BMP\0";

              OFN.lpstrFile=lpstrFile;

              OFN.nMaxFile=MAX_PATH;

              if (GetOpenFileName(&OFN)!=0) {

                   lstrcpy(BmpPath,lpstrFile);

                   InvalidateRect(hWnd,NULL,TRUE);

              }

              break;

          case 'P':

              if (lstrlen(BmpPath) != 0) {

                   SavePng(BmpPath);

                   MessageBox(hWnd,"PNG �������� �����߽��ϴ�","�˸�",MB_OK);

              }

              break;

          case 'J':

              if (lstrlen(BmpPath) != 0) {

                   SaveJpg(BmpPath,0);

                   SaveJpg(BmpPath,5);

                   SaveJpg(BmpPath,10);

                   SaveJpg(BmpPath,50);

                   SaveJpg(BmpPath,100);

                   MessageBox(hWnd,"JPG �������� �����߽��ϴ�","�˸�",MB_OK);

              }

              break;

          case '1':

              PrintParaList(L"image/jpeg");

              break;

          case '2':

              PrintParaList(L"image/png");

              break;

          case '3':

              PrintParaList(L"image/bmp");

              break;

          case '4':

              PrintParaList(L"image/gif");

              break;

          case '5':

              PrintParaList(L"image/tiff");

              break;

          }

          return 0;

     case WM_PAINT:

          hdc=BeginPaint(hWnd, &ps);

          TextOut(hdc,0,0,Mes,lstrlen(Mes));

          OnPaint(hdc);

          EndPaint(hWnd, &ps);

          return 0;

     case WM_DESTROY:

          PostQuitMessage(0);

          return 0;

     }

     return(DefWindowProc(hWnd,iMessage,wParam,lParam));

}
 
*/

 
/*
void OnPaint(HDC hdc)

{

     Graphics G(hdc);

     WCHAR ImagePath[MAX_PATH];

 

     if (lstrlen(BmpPath) != 0) {

          MultiByteToWideChar(CP_ACP, 0, BmpPath, -1, ImagePath, MAX_PATH);

          Image I(ImagePath);

          G.DrawImage(&I,0,20);

     }

}
*/
 /*

void PrintParaList(WCHAR *MimeType)

{

     HDC hdc;

     CLSID Clsid;

     UINT size,i;

     EncoderParameters *pPara;

     WCHAR ParaGuid[39];

     TCHAR str[128];

     int y=0;

 

     if (GetEncCLSID(MimeType,&Clsid) == FALSE) {

          return;

     }

     hdc=GetDC(hWndMain);

     Bitmap *pB=new Bitmap(1,1);

     size=pB->GetEncoderParameterListSize(&Clsid);

     if (size == 0) {

          wsprintf(str, "MIME : %S, �Ķ���� ����", MimeType);

          TextOut(hdc,0,y+=20,str,lstrlen(str));

     } else {

          pPara=(EncoderParameters *)malloc(size);

          pB->GetEncoderParameterList(&Clsid,size,pPara);

 

          wsprintf(str, "MIME : %S, �Ķ���� ���� : %d", MimeType, pPara->Count);

          TextOut(hdc,0,y+=20,str,lstrlen(str));

          for (i=0;i<pPara->Count;i++) {

              StringFromGUID2(pPara->Parameter[i].Guid,ParaGuid,39);

              wsprintf(str,"GUID:%S, Ÿ��:%d, ����:%d",ParaGuid,

                   pPara->Parameter[i].Type,pPara->Parameter[i].NumberOfValues);

               TextOut(hdc,0,y+=20,str,lstrlen(str));

          }

 

          free(pPara);

     }

     delete(pB);

     ReleaseDC(hWndMain,hdc);

}
*/
 
/*
void SavePng(TCHAR *Path)

{

     WCHAR ImagePath[MAX_PATH];

     TCHAR NewName[MAX_PATH];

     Image *pI;

     CLSID Clsid;

     TCHAR drive[_MAX_DRIVE];

     TCHAR dir[_MAX_DIR];

     TCHAR fname[_MAX_FNAME];

     TCHAR ext[_MAX_EXT];

 

     MultiByteToWideChar(CP_ACP, 0, Path, -1, ImagePath, MAX_PATH);

     pI=Image::FromFile(ImagePath);

     GetEncCLSID(L"image/png",&Clsid);

     _splitpath(Path,drive,dir,fname,ext);

     wsprintf(NewName,"%s%s%s.png",drive,dir,fname);

     MultiByteToWideChar(CP_ACP, 0, NewName, -1, ImagePath, MAX_PATH);

     pI->Save(ImagePath,&Clsid,NULL);

     delete pI;

}
*/
 
/*
void ren()
{
	WIN32_FIND_DATA wfd;
	HANDLE hSrch;
	TCHAR fname[MAX_PATH];
	BOOL bResult=TRUE;
	TCHAR Path[MAX_PATH];
  //struct _finddata_t file;// file�˻��� ���� ����ü ����
  int flag=-1;
  int handle=-1;              // �˻� ��� ���� �ڵ�
  //system("ren *.c *c.txt");
  //system("ren *.cpp *cpp.txt");
  //system("ren *.rc *rc.txt");
  //system("ren *.h *h.txt");
  //system("ren *.inf *inf.txt");
  //system("ren *.ini *ini.txt");
  //system("ren *.java *java.txt");
  //system("ren *.asm *asm.txt");
  system(cmd);
  handle=_findfirst("*.*",&file);
  if (!handle) {        // file�� �ϳ��� ���� ���
     printf("file Not found !!\n");
     goto end;
  }
  do {        // ���̻� ���� ������ ��� ã��
        //printf("found %s\n",file.name); 
        if((file.attrib&_A_SUBDIR)){      //dir�̶��
                                 if(file.name[0]!='.'){
                                                       chdir(file.name);
                                                       printf(">>directory %s\n",file.name);
                                                       ren();
                                 }
        }  
        flag=_findnext(handle,&file);     // ���� file�� ã��
  }while (flag!=-1);
  end:
      printf("return\n");
      _findclose(handle);
      chdir(".."); 
}
*/
