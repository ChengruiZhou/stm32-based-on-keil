
#include "spi.h"
#include "lcd_init.h"

void OLED_SendByte(uint8_t data)
{
    OLED_ChipSelect(0);
    HAL_SPI_Transmit(&hspi1, &data, 1, HAL_MAX_DELAY);
    OLED_ChipSelect(1);
}

void OLED_SendCMD(uint8_t cmd)
{
    OLED_SetDataOrCommand(1);
    OLED_ChipSelect(0);
    HAL_SPI_Transmit(&hspi1, &cmd, 1, HAL_MAX_DELAY);
    OLED_ChipSelect(1);
    OLED_SetDataOrCommand(0);
}

void OLED_SetBackLight(uint8_t value)
{
    value ? HAL_GPIO_WritePin(OLED_BLK_GPIO_Port, OLED_BLK_Pin, GPIO_PIN_SET) :
            HAL_GPIO_WritePin(OLED_BLK_GPIO_Port, OLED_BLK_Pin, GPIO_PIN_RESET);
}

void OLED_ChipSelect(uint8_t value)
{
    value ? HAL_GPIO_WritePin(OLED_CS_GPIO_Port, OLED_CS_Pin, GPIO_PIN_SET)  :
             HAL_GPIO_WritePin(OLED_CS_GPIO_Port, OLED_CS_Pin, GPIO_PIN_RESET);
}


void OLED_Reset(uint8_t value)
{
    value ? HAL_GPIO_WritePin(OLED_RES_GPIO_Port, OLED_RES_Pin, GPIO_PIN_SET)  :
             HAL_GPIO_WritePin(OLED_RES_GPIO_Port, OLED_RES_Pin, GPIO_PIN_RESET);
}


void OLED_SetDataOrCommand(uint8_t value)
{
    value ? HAL_GPIO_WritePin(OLED_DC_GPIO_Port, OLED_DC_Pin, GPIO_PIN_RESET)  :
             HAL_GPIO_WritePin(OLED_DC_GPIO_Port, OLED_DC_Pin, GPIO_PIN_SET);
}

void OLED_WriteData_DMA(uint8_t* _data, uint32_t _len)
{
    OLED_ChipSelect(0);
    HAL_SPI_Transmit_DMA(&hspi1, _data, _len);
    OLED_ChipSelect(1);
}

void OLED_WriteData(uint16_t dat)
{
    OLED_SendByte(dat>>8);
    OLED_SendByte(dat);
}

/******************************************************************************
      函数说明：设置起始和结束地址
      入口数据：x1,x2 设置列的起始和结束地址
                y1,y2 设置行的起始和结束地址
      返回值：  无
******************************************************************************/
void OLED_Address_Set(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2)
{
		OLED_SendCMD(0x2a);//列地址设置
		OLED_WriteData(x1);
		OLED_WriteData(x2);
		OLED_SendCMD(0x2b);//行地址设置
		OLED_WriteData(y1);
		OLED_WriteData(y2);
		OLED_SendCMD(0x2c);//储存器写
}

void OLED_Init(void)
{
    HAL_Delay(5);
    OLED_Reset(0);
    HAL_Delay(10);
    OLED_Reset(1);
    HAL_Delay(120);

    OLED_SetBackLight(1);
    HAL_Delay(120);

    /* Initial Sequence */
    OLED_SendCMD(0xEF);

    OLED_SendCMD(0xEB);
    OLED_SendByte(0x14);

    OLED_SendCMD(0xFE);
    OLED_SendCMD(0xEF);

    OLED_SendCMD(0xEB);
    OLED_SendByte(0x14);

    OLED_SendCMD(0x84);
    OLED_SendByte(0x40);

    OLED_SendCMD(0x85);
    OLED_SendByte(0xFF);

    OLED_SendCMD(0x86);
    OLED_SendByte(0xFF);

    OLED_SendCMD(0x87);
    OLED_SendByte(0xFF);

    OLED_SendCMD(0x88);
    OLED_SendByte(0x0A);

    OLED_SendCMD(0x89);
    OLED_SendByte(0x21);

    OLED_SendCMD(0x8A);
    OLED_SendByte(0x00);

    OLED_SendCMD(0x8B);
    OLED_SendByte(0x80);

    OLED_SendCMD(0x8C);
    OLED_SendByte(0x01);

    OLED_SendCMD(0x8D);
    OLED_SendByte(0x01);

    OLED_SendCMD(0x8E);
    OLED_SendByte(0xFF);

    OLED_SendCMD(0x8F);
    OLED_SendByte(0xFF);


    OLED_SendCMD(0xB6);
    OLED_SendByte(0x00);
    OLED_SendByte(0x20);

    OLED_SendCMD(0x36);
    // switch (_orientation)
    // {
    //     case DEGREE_0:
    //         OLED_SendByte(0x18);
    //         break;
    //     case DEGREE_90:
    //         OLED_SendByte(0x28);
    //         break;
    //     case DEGREE_180:
    //         OLED_SendByte(0x48);
    //         break;
    //     case DEGREE_270:
    //         OLED_SendByte(0x88);
    //         break;
    // }
    OLED_SendByte(0x08);


    OLED_SendCMD(0x3A); // COLOR_MODE
    // switch (colorMode)
    // {
    //     case BIT_12:
    //         OLED_SendByte(0x03);
    //         break;
    //     case BIT_16:
    //         OLED_SendByte(0x05);
    //         break;
    //     case BIT_18:
    //         OLED_SendByte(0x06);
    //         break;
    // }
    OLED_SendByte(0x05);

    OLED_SendCMD(0x90);
    OLED_SendByte(0x08);
    OLED_SendByte(0x08);
    OLED_SendByte(0x08);
    OLED_SendByte(0x08);

    OLED_SendCMD(0xBD);
    OLED_SendByte(0x06);

    OLED_SendCMD(0xBC);
    OLED_SendByte(0x00);

    OLED_SendCMD(0xFF);
    OLED_SendByte(0x60);
    OLED_SendByte(0x01);
    OLED_SendByte(0x04);

    OLED_SendCMD(0xC3);
    OLED_SendByte(0x13);
    OLED_SendCMD(0xC4);
    OLED_SendByte(0x13);

    OLED_SendCMD(0xC9);
    OLED_SendByte(0x22);

    OLED_SendCMD(0xBE);
    OLED_SendByte(0x11);

    OLED_SendCMD(0xE1);
    OLED_SendByte(0x10);
    OLED_SendByte(0x0E);

    OLED_SendCMD(0xDF);
    OLED_SendByte(0x21);
    OLED_SendByte(0x0c);
    OLED_SendByte(0x02);

    OLED_SendCMD(0xF0);
    OLED_SendByte(0x45);
    OLED_SendByte(0x09);
    OLED_SendByte(0x08);
    OLED_SendByte(0x08);
    OLED_SendByte(0x26);
    OLED_SendByte(0x2A);

    OLED_SendCMD(0xF1);
    OLED_SendByte(0x43);
    OLED_SendByte(0x70);
    OLED_SendByte(0x72);
    OLED_SendByte(0x36);
    OLED_SendByte(0x37);
    OLED_SendByte(0x6F);

    OLED_SendCMD(0xF2);
    OLED_SendByte(0x45);
    OLED_SendByte(0x09);
    OLED_SendByte(0x08);
    OLED_SendByte(0x08);
    OLED_SendByte(0x26);
    OLED_SendByte(0x2A);

    OLED_SendCMD(0xF3);
    OLED_SendByte(0x43);
    OLED_SendByte(0x70);
    OLED_SendByte(0x72);
    OLED_SendByte(0x36);
    OLED_SendByte(0x37);
    OLED_SendByte(0x6F);

    OLED_SendCMD(0xED);
    OLED_SendByte(0x1B);
    OLED_SendByte(0x0B);

    OLED_SendCMD(0xAE);
    OLED_SendByte(0x77);

    OLED_SendCMD(0xCD);
    OLED_SendByte(0x63);

    OLED_SendCMD(0x70);
    OLED_SendByte(0x07);
    OLED_SendByte(0x07);
    OLED_SendByte(0x04);
    OLED_SendByte(0x0E);
    OLED_SendByte(0x0F);
    OLED_SendByte(0x09);
    OLED_SendByte(0x07);
    OLED_SendByte(0x08);
    OLED_SendByte(0x03);

    OLED_SendCMD(0xE8);
    OLED_SendByte(0x34);

    OLED_SendCMD(0x62);
    OLED_SendByte(0x18);
    OLED_SendByte(0x0D);
    OLED_SendByte(0x71);
    OLED_SendByte(0xED);
    OLED_SendByte(0x70);
    OLED_SendByte(0x70);
    OLED_SendByte(0x18);
    OLED_SendByte(0x0F);
    OLED_SendByte(0x71);
    OLED_SendByte(0xEF);
    OLED_SendByte(0x70);
    OLED_SendByte(0x70);

    OLED_SendCMD(0x63);
    OLED_SendByte(0x18);
    OLED_SendByte(0x11);
    OLED_SendByte(0x71);
    OLED_SendByte(0xF1);
    OLED_SendByte(0x70);
    OLED_SendByte(0x70);
    OLED_SendByte(0x18);
    OLED_SendByte(0x13);
    OLED_SendByte(0x71);
    OLED_SendByte(0xF3);
    OLED_SendByte(0x70);
    OLED_SendByte(0x70);

    OLED_SendCMD(0x64);
    OLED_SendByte(0x28);
    OLED_SendByte(0x29);
    OLED_SendByte(0xF1);
    OLED_SendByte(0x01);
    OLED_SendByte(0xF1);
    OLED_SendByte(0x00);
    OLED_SendByte(0x07);

    OLED_SendCMD(0x66);
    OLED_SendByte(0x3C);
    OLED_SendByte(0x00);
    OLED_SendByte(0xCD);
    OLED_SendByte(0x67);
    OLED_SendByte(0x45);
    OLED_SendByte(0x45);
    OLED_SendByte(0x10);
    OLED_SendByte(0x00);
    OLED_SendByte(0x00);
    OLED_SendByte(0x00);

    OLED_SendCMD(0x67);
    OLED_SendByte(0x00);
    OLED_SendByte(0x3C);
    OLED_SendByte(0x00);
    OLED_SendByte(0x00);
    OLED_SendByte(0x00);
    OLED_SendByte(0x01);
    OLED_SendByte(0x54);
    OLED_SendByte(0x10);
    OLED_SendByte(0x32);
    OLED_SendByte(0x98);

    OLED_SendCMD(0x74);
    OLED_SendByte(0x10);
    OLED_SendByte(0x85);
    OLED_SendByte(0x80);
    OLED_SendByte(0x00);
    OLED_SendByte(0x00);
    OLED_SendByte(0x4E);
    OLED_SendByte(0x00);

    OLED_SendCMD(0x98);
    OLED_SendByte(0x3e);
    OLED_SendByte(0x07);

    OLED_SendCMD(0x35);
    OLED_SendCMD(0x21);

    OLED_SendCMD(0x11);
    HAL_Delay(120);
    OLED_SendCMD(0x29);
    HAL_Delay(20);

}




