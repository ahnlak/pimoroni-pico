//------------------------------------------------------
// SSD1306 OLED driver for Pico
//
// Attempting to follow the sample structure of other
// drivers in pimoroni-pico, so if it's wrong it's all
// @gadgetoid's fault.
//------------------------------------------------------

#include "ssd1306.hpp"

namespace pimoroni {

  // init - allocates a suitable screen buffer, and attempts to initialise
  //        the device.
  // 
  SSD1306::SSD1306(I2C *i2c, uint8_t width, uint8_t height, uint8_t address) :
    i2c(i2c), width(width), height(height), address(address)
  {
    /* Allocate the screen buffer. */

    /* Send the start-up command sequence. */
  }

  // reset - sends commands to power the display off and on; the best we can do
  //         in terms of a formal reset.
  //
  void SSD1306::reset( void ) {
    /* Turn the display off / on */

  }

  void SSD1306::power_on()
  {

  }

  void SSD1306::power_off()
  {

  }

  void SSD1306::clear()
  {

  }

  void SSD1306::pixel(uint8_t x, uint8_t y)
  {

  }

  void SSD1306::show()
  {

  }

  // Misc functions now, for print access in micropython (apparently)
  //
  i2c_inst_t* SSD1306::get_i2c() const {
    return i2c->get_i2c();
  }

  int SSD1306::get_sda() const {
    return i2c->get_sda();
  }

  int SSD1306::get_scl() const {
    return i2c->get_scl();
  }

  int SSD1306::get_int() const {
    return interrupt;
  }
}
