//------------------------------------------------------
// SSD1306 OLED driver for Pico
//
// Attempting to follow the sample structure of other
// drivers in pimoroni-pico, so if it's wrong it's all
// @gadgetoid's fault.
//------------------------------------------------------

#pragma once

#include <string>

#include "hardware/i2c.h"
#include "hardware/gpio.h"
#include "common/pimoroni_common.hpp"
#include "common/pimoroni_i2c.hpp"

namespace pimoroni {

  class SSD1306 {
    //--------------------------------------------------
    // Constants
    //--------------------------------------------------
  public:
    static const uint8_t DEFAULT_I2C_ADDRESS  = 0x3C;


    //--------------------------------------------------
    // Enums
    //--------------------------------------------------
  public:
    enum class ssd1306_command : uint8_t {
      SET_CONTRAST = 0x81,
      SET_ENTIRE_ON = 0xA4,
      SET_NORM_INV = 0xA6,
      SET_DISP = 0xAE,
      SET_MEM_ADDR = 0x20,
      SET_COL_ADDR = 0x21,
      SET_PAGE_ADDR = 0x22,
      SET_DISP_START_LINE = 0x40,
      SET_SEG_REMAP = 0xA0,
      SET_MUX_RATIO = 0xA8,
      SET_COM_OUT_DIR = 0xC0,
      SET_DISP_OFFSET = 0xD3,
      SET_COM_PIN_CFG = 0xDA,
      SET_DISP_CLK_DIV = 0xD5,
      SET_PRECHARGE = 0xD9,
      SET_VCOM_DESEL = 0xDB,
      SET_CHARGE_PUMP = 0x8D      
    };


    //--------------------------------------------------
    // Variables
    //--------------------------------------------------
  private:
    I2C *i2c;

    // interface pins with our standard defaults where appropriate
    uint8_t address = DEFAULT_I2C_ADDRESS;

    // screen metrics
    uint8_t width;
    uint8_t height;
    uint8_t pages;

    bool external_vcc;

    // screen buffer
    uint8_t *buffer;
    size_t   bufsize;


    //--------------------------------------------------
    // Constructors/Destructor
    //--------------------------------------------------
  public:
    SSD1306(uint8_t width, uint8_t height, uint8_t address = DEFAULT_I2C_ADDRESS) : SSD1306(new I2C(), width, height, address) {};
    SSD1306(I2C *i2c, uint8_t width, uint8_t height, uint8_t address = DEFAULT_I2C_ADDRESS);


    //--------------------------------------------------
    // Methods
    //--------------------------------------------------
  public:

    // main interface
    void reset();
    void power_on();
    void power_off();
    void clear();
    void pixel(uint8_t x, uint8_t y);
    void show();

    // For print access in micropython
    i2c_inst_t* get_i2c() const;
    int get_sda() const;
    int get_scl() const;
    int get_int() const;


  private:
    void write_val(uint8_t val);
    void write(const uint8_t *buffer, size_t buflen);

  };

}
