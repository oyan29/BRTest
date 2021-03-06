/*
************************************************************************
【File Name】LED操作関数(アプリケーション部)
【Description】
【Revision History】
   REV.00 2014-02-11  BY R.ISHIKAWA
   REV.XX 20XX-XX-XX  BY X.XXXXXX
   REV.XX 20XX-XX-XX  BY X.XXXXXX
   REV.XX 20XX-XX-XX  BY X.XXXXXX

                      (C) 2013 IPL CORPORATION All Rights Reserved
************************************************************************
*/

/*
 * インクルード
 */
#include "HAL.h"
#include "PF_Common.h"

/*
 * 定数定義
 */

/*
 * 外部関数宣言
 */

/*
 * 内部関数宣言
 */

/*
 * グローバル変数宣言
 */

/******************************************************************************
【名称】LED操作関数
【再入】非リエントラント
【入力】LED1(オレンジ)状態
【出力】なし
【戻値】なし
【処理】LED1の状態を引数で指定した状態に変更する
******************************************************************************/
void APP_LED1_Set(UB ubLed1)
{
	// ハードウェア面のLED操作関数を呼び出す
	HAL_LED1_Set(ubLed1);
}

/******************************************************************************
【名称】LED操作関数
【再入】非リエントラント
【入力】LED2(緑)状態
【出力】なし
【戻値】なし
【処理】2の状態を引数で指定した状態に変更する
******************************************************************************/
void APP_LED2_Set(UB ubLed2)
{
	// ハードウェア面のLED操作関数を呼び出す
	HAL_LED2_Set(ubLed2);
}
