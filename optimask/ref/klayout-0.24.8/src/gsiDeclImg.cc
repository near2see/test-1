
/*

  KLayout Layout Viewer
  Copyright (C) 2006-2016 Matthias Koefferlein

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

*/



#include "gsiDecl.h"
#include "imgObject.h"
#include "imgService.h"
#include "layLayoutView.h"

namespace gsi
{

static img::DataMapping *new_data_mapping ()
{
  return new img::DataMapping ();
}

static void clear_colormap (img::DataMapping *dm)
{
  dm->false_color_nodes.clear ();
}

static void add_colormap (img::DataMapping *dm, double value, lay::color_t color)
{
  dm->false_color_nodes.push_back (std::make_pair (value, QColor (color)));
}

static size_t num_colormap_entries (const img::DataMapping *dm)
{
  return dm->false_color_nodes.size ();
}

static lay::color_t colormap_color (const img::DataMapping *dm, size_t i)
{
  if (i < dm->false_color_nodes.size ()) {
    return dm->false_color_nodes [i].second.rgb ();
  } else {
    return 0;
  }
}

static double colormap_value (const img::DataMapping *dm, size_t i)
{
  if (i < dm->false_color_nodes.size ()) {
    return dm->false_color_nodes [i].first;
  } else {
    return 0.0;
  }
}

static void set_brightness (img::DataMapping *dm, double b)
{
  dm->brightness = b;
}

static double brightness (const img::DataMapping *dm)
{
  return dm->brightness;
}

static void set_contrast (img::DataMapping *dm, double c)
{
  dm->contrast = c;
}

static double contrast (const img::DataMapping *dm)
{
  return dm->contrast;
}

static void set_gamma (img::DataMapping *dm, double g)
{
  dm->gamma = g;
}

static double gamma (const img::DataMapping *dm)
{
  return dm->gamma;
}

static void set_red_gain (img::DataMapping *dm, double g)
{
  dm->red_gain = g;
}

static double red_gain (const img::DataMapping *dm)
{
  return dm->red_gain;
}

static void set_green_gain (img::DataMapping *dm, double g)
{
  dm->green_gain = g;
}

static double green_gain (const img::DataMapping *dm)
{
  return dm->green_gain;
}

static void set_blue_gain (img::DataMapping *dm, double g)
{
  dm->blue_gain = g;
}

static double blue_gain (const img::DataMapping *dm)
{
  return dm->blue_gain;
}

gsi::Class<img::DataMapping> decl_ImageDataMapping ("ImageDataMapping", 
  gsi::constructor ("new", &gsi::new_data_mapping,
    "@brief Create a new data mapping object with default settings"
  ) +
  gsi::method_ext ("clear_colormap", &gsi::clear_colormap, 
    "@brief The the color map of this data mapping object."
  ) +
  gsi::method_ext ("add_colormap_entry", &gsi::add_colormap, 
    "@brief Add a colormap entry for this data mapping object.\n"
    "@args value, color\n"
    "@param value The value at which the given color should be applied.\n"
    "@param color The color to apply (a 32 bit RGB value).\n"
    "\n"
    "This settings establishes a color mapping for a given value in the monochrome channel. "
    "The color must be given as a 32 bit integer, where the lowest order byte describes the "
    "blue component (0 to 255), the second byte the green component and the third byte the "
    "red component, i.e. 0xff0000 is red and 0x0000ff is blue. "
  ) +
  gsi::method_ext ("num_colormap_entries", &gsi::num_colormap_entries,
    "@brief Returns the current number of color map entries.\n"
    "@return The number of entries.\n"
  ) +
  gsi::method_ext ("colormap_color", &gsi::colormap_color, 
    "@brief Returns the color for a given color map entry.\n"
    "@args n\n"
    "@param n The index of the entry (0..\\num_colormap_entries-1)\n"
    "@return The color (see \\add_colormap_entry for a description).\n"
  ) +
  gsi::method_ext ("colormap_value", &gsi::colormap_value, 
    "@brief Returns the vlue for a given color map entry.\n"
    "@args n\n"
    "@param n The index of the entry (0..\\num_colormap_entries-1)\n"
    "@return The value (see \\add_colormap_entry for a description).\n"
  ) +
  gsi::method_ext ("brightness=", &gsi::set_brightness, 
    "@brief Set the brightness\n"
    "@args brightness\n"
    "See \\brightness for a description of this property.\n"
  ) +
  gsi::method_ext ("brightness", &gsi::brightness, 
    "@brief The brightness value\n"
    "\n"
    "The brightness is a double value between roughly -1.0 and 1.0. \n"
    "Neutral (original) brightness is 0.0.\n"
  ) +
  gsi::method_ext ("contrast=", &gsi::set_contrast, 
    "@brief Set the contrast\n"
    "@args contrast\n"
    "See \\contrast for a description of this property.\n"
  ) +
  gsi::method_ext ("contrast", &gsi::contrast, 
    "@brief The contrast value\n"
    "\n"
    "The contrast is a double value between roughly -1.0 and 1.0. \n"
    "Neutral (original) contrast is 0.0.\n"
  ) +
  gsi::method_ext ("gamma=", &gsi::set_gamma, 
    "@brief Set the gamma\n"
    "@args gamma\n"
    "See \\gamma for a description of this property.\n"
  ) +
  gsi::method_ext ("gamma", &gsi::gamma, 
    "@brief The gamma value\n"
    "\n"
    "The gamma value allows to adjust for non-linearities in the display chain and to enhance contrast.\n"
    "A value for linear intensity reproduction on the screen is roughly 0.5. The exact value depends on the \n"
    "monitor calibration. Values below 1.0 give a \"softer\" appearance while values above 1.0 give a \"harder\" appearance.\n"
  ) +
  gsi::method_ext ("red_gain=", &gsi::set_red_gain, 
    "@brief Set the red_gain\n"
    "@args red_gain\n"
    "See \\red_gain for a description of this property.\n"
  ) +
  gsi::method_ext ("red_gain", &gsi::red_gain, 
    "@brief The red channel gain\n"
    "\n"
    "This value is the multiplier by which the red channel is scaled after applying \n"
    "false color transformation and contrast/brightness/gamma.\n"
    "\n"
    "1.0 is a neutral value. The gain should be >=0.0.\n"
  ) +
  gsi::method_ext ("green_gain=", &gsi::set_green_gain, 
    "@brief Set the green_gain\n"
    "@args green_gain\n"
    "See \\green_gain for a description of this property.\n"
  ) +
  gsi::method_ext ("green_gain", &gsi::green_gain, 
    "@brief The green channel gain\n"
    "\n"
    "This value is the multiplier by which the green channel is scaled after applying \n"
    "false color transformation and contrast/brightness/gamma.\n"
    "\n"
    "1.0 is a neutral value. The gain should be >=0.0.\n"
  ) +
  gsi::method_ext ("blue_gain=", &gsi::set_blue_gain, 
    "@brief Set the blue_gain\n"
    "@args blue_gain\n"
    "See \\blue_gain for a description of this property.\n"
  ) +
  gsi::method_ext ("blue_gain", &gsi::blue_gain, 
    "@brief The blue channel gain\n"
    "\n"
    "This value is the multiplier by which the blue channel is scaled after applying \n"
    "false color transformation and contrast/brightness/gamma.\n"
    "\n"
    "1.0 is a neutral value. The gain should be >=0.0.\n"
  ),
  "@brief A structure describing the data mapping of an image object\n"
  "\n"
  "Data mapping is the process of transforming the data into RGB pixel values.\n"
  "This implementation provides four adjustment steps: first, in the case of monochrome\n"
  "data, the data is converted to a RGB triplet using the color map. The default color map\n"
  "will copy the value to all channels rendering a gray scale. After having normalized the data \n"
  "to 0..1 cooresponding to the min_value and max_value settings of the image, a color channel-independent\n"
  "brightness and contrast adjustment is applied. Then, a per-channel multiplier (red_gain, green_gain,\n"
  "blue_gain) is applied. Finally, the gamma function is applied and the result converted into a 0..255 \n"
  "pixel value range and clipped.\n"
);


static img::Object *new_image ()
{
  return new img::Object ();
}

static img::Object *new_image_f (const std::string &filename)
{
  return new img::Object (filename, db::DCplxTrans ());
}

static img::Object *new_image_ft (const std::string &filename, const db::DCplxTrans &trans)
{
  return new img::Object (filename, trans);
}

/* 
static img::Object *new_image_whc (size_t w, size_t h, bool color)
{
  return new img::Object (w, h, db::DCplxTrans (), color);
}

static img::Object *new_image_whtc (size_t w, size_t h, const db::DCplxTrans &trans, bool color)
{
  return new img::Object (w, h, trans, color);
}
*/

static img::Object *new_image_whd (size_t w, size_t h, const std::vector<double> &data)
{
  return new img::Object (w, h, db::DCplxTrans (), data);
}

static img::Object *new_image_whtd (size_t w, size_t h, const db::DCplxTrans &trans, const std::vector<double> &data)
{
  return new img::Object (w, h, trans * db::DCplxTrans (db::DPoint (0.5 * w, 0.5 * h)), data);
}

static img::Object *new_image_whrgb (size_t w, size_t h, const std::vector<double> &red, const std::vector<double> &green, const std::vector<double> &blue)
{
  return new img::Object (w, h, db::DCplxTrans (), red, green, blue);
}

static img::Object *new_image_whtrgb (size_t w, size_t h, const db::DCplxTrans &trans, const std::vector<double> &red, const std::vector<double> &green, const std::vector<double> &blue)
{
  return new img::Object (w, h, trans * db::DCplxTrans (db::DPoint (0.5 * w, 0.5 * h)), red, green, blue);
}

static double img_get_pixel_width (const img::Object *obj)
{
  return obj->matrix ().mag_x ();
}

static void img_set_pixel_width (img::Object *obj, double w)
{
  db::Matrix3d m = obj->matrix ();
  db::Matrix3d n = db::Matrix3d::perspective (m.perspective_tilt_x (1.0), m.perspective_tilt_y (1.0), 1.0) * db::Matrix3d::disp (m.disp ()) * db::Matrix3d::rotation (m.angle ()) * db::Matrix3d::shear (m.shear_angle ()) * db::Matrix3d::mag (w, m.mag_y ()) * db::Matrix3d::mirror (m.is_mirror ());
  obj->set_matrix (n);
}

static double img_get_pixel_height (const img::Object *obj)
{
  return obj->matrix ().mag_y ();
}

static void img_set_pixel_height (img::Object *obj, double h)
{
  db::Matrix3d m = obj->matrix ();
  db::Matrix3d n = db::Matrix3d::perspective (m.perspective_tilt_x (1.0), m.perspective_tilt_y (1.0), 1.0) * db::Matrix3d::disp (m.disp ()) * db::Matrix3d::rotation (m.angle ()) * db::Matrix3d::shear (m.shear_angle ()) * db::Matrix3d::mag (m.mag_x (), h) * db::Matrix3d::mirror (m.is_mirror ());
  obj->set_matrix (n);
}

static db::DCplxTrans img_get_trans (const img::Object *obj)
{
  const db::Matrix3d &m = obj->matrix ();
  return db::DCplxTrans (1.0, m.angle (), m.is_mirror (), m.disp ()) * db::DCplxTrans (db::DPoint (obj->width () * -0.5 * m.mag_x (), obj->height () * -0.5 * m.mag_y ()));
}

static void img_set_trans (img::Object *obj, const db::DCplxTrans &t)
{
  //  to be consistent with the definition of KLayout 0.21, we keep mag_x and mag_y as pixel dimensions
  //  and refer to the image's pixel 0,0 as the rotation center.
  db::Matrix3d m = obj->matrix ();
  db::Matrix3d n = db::Matrix3d::disp (t.disp ()) * db::Matrix3d::rotation (t.angle ()) * db::Matrix3d::mag (t.mag () * m.mag_x (), t.mag () * m.mag_y ()) * db::Matrix3d::mirror (t.is_mirror ()) * db::Matrix3d::disp (db::DPoint (obj->width () * 0.5, obj->height () * 0.5));
  obj->set_matrix (n);
}

gsi::Class<img::Object> decl_Image ("Image", 
  gsi::constructor ("new", &gsi::new_image,
    "@brief Create a new image with the default attributes"
    "\n"
    "This will create an empty image without data and no particular pixel width or related.\n"
    "Use the \\read_file or \\set_data methods to set image properties and pixel values.\n"
  ) +
  gsi::constructor ("new", &gsi::new_image_f,
    "@brief Constructor from a image file \n"
    "@args filename\n"
    "\n"
    "This constructor creates an image object from a file (which can have any format supported by Qt) and \n"
    "a unit transformation. The image will originally be put to position 0,0 (lower left corner) and each pixel\n"
    "will have a size of 1 (micron). \n"
    "\n"
    "@param filename The path to the image file to load.\n"
  ) +
  gsi::constructor ("new", &gsi::new_image_ft,
    "@brief Constructor from a image file \n"
    "@args filename, trans\n"
    "\n"
    "This constructor creates an image object from a file (which can have any format supported by Qt) and \n"
    "a transformation. The image will originally be put to position 0,0 (lower left corner) and each pixel\n"
    "will have a size of 1. The transformation describes how to transform this image into micron space.\n"
    "\n"
    "@param filename The path to the image file to load.\n"
    "@param trans The transformation to apply to the image when displaying it.\n"
  ) +
  gsi::constructor ("new", &gsi::new_image_whd,
    "@brief Constructor for a monochrome image with the given pixel values\n"
    "@args w, h, data\n"
    "\n"
    "This constructor creates an image from the given pixel values. The values have to be organized\n"
    "line by line. Each line must consist of \"w\" values where the first value is the leftmost pixel.\n"
    "Note, that the rows are oriented in the mathematical sense (first one is the lowest) contrary to \n"
    "the common convention for image data.\n"
    "Initially the pixel width and heigt will be 1 micron and the data range will be 0 to 1.0 (black to white level). \n"
    "To adjust the data range use the \\min_value and \\max_value properties.\n"
    "\n"
    "@param w The width of the image\n"
    "@param h The height of the image\n"
    "@param d The data (see method description)\n"
  ) +
  gsi::constructor ("new", &gsi::new_image_whtd,
    "@brief Constructor for a monochrome image with the given pixel values\n"
    "@args w, h, trans, data\n"
    "\n"
    "This constructor creates an image from the given pixel values. The values have to be organized\n"
    "line by line. Each line must consist of \"w\" values where the first value is the leftmost pixel.\n"
    "Note, that the rows are oriented in the mathematical sense (first one is the lowest) contrary to \n"
    "the common convention for image data.\n"
    "Initially the pixel width and heigt will be 1 micron and the data range will be 0 to 1.0 (black to white level). \n"
    "To adjust the data range use the \\min_value and \\max_value properties.\n"
    "\n"
    "@param w The width of the image\n"
    "@param h The height of the image\n"
    "@param trans The transformation from pixel space to micron space\n"
    "@param d The data (see method description)\n"
  ) +
  /*  HINT: these declarations cannot be used currently since any array is case to the boolean color parameter
  gsi::constructor ("new", &img::new_image_whc,
    "@brief Constructor for monochrome or color images with zero pixel values\n"
    "@args w, h, color\n"
    "\n"
    "This constructor creates an image object from a data set describing one monochrome channel\n"
    "or three color channels.\n"
    "Each channel consists of an array of x*y values where the first \"x\" values describe the first (lowest!) row\n"
    "and so on. Note, that the rows are oriented in the mathematical sense (first one is the lowest) contrary to \n"
    "the common convention for image data.\n"
    "The data fields can be accessed with the \"data\", \"set_data\", \"pixel\" or \"set_pixel\" methods.\n"
    "Initially the pixel width and heigt will be 1 micron and the data range will be 0 to 1.0 (black to white level). \n"
    "\n"
    "@param w The width of the image\n"
    "@param h The height of the image\n"
    "@param color True to create a color image.\n"
  ) +
  gsi::constructor ("new", &img::new_image_whtc,
    "@brief Constructor for monochrome or color images with zero pixel values\n"
    "@args w, h, trans, color\n"
    "\n"
    "This constructor creates an image object from a data set describing one monochrome channel\n"
    "or three color channels.\n"
    "Each channel consists of an array of x*y values where the first \"x\" values describe the first (lowest!) row\n"
    "and so on. Note, that the rows are oriented in the mathematical sense (first one is the lowest) contrary to \n"
    "the common convention for image data.\n"
    "The data fields can be accessed with the \"data\", \"set_data\", \"pixel\" or \"set_pixel\" methods.\n"
    "Initially the pixel width and heigt will be 1 micron and the data range will be 0 to 1.0 (black to white level). \n"
    "\n"
    "@param w The width of the image\n"
    "@param h The height of the image\n"
    "@param trans The transformation to apply to the image when displaying it\n"
    "@param color True to create a color image.\n"
  ) +
  */
  gsi::constructor ("new", &gsi::new_image_whrgb,
    "@brief Constructor for a color image with the given pixel values\n"
    "@args w, h, red, green, blue\n"
    "\n"
    "This constructor creates an image from the given pixel values. The values have to be organized\n"
    "line by line and separated by color channel. Each line must consist of \"w\" values where the first value is the leftmost pixel.\n"
    "Note, that the rows are oriented in the mathematical sense (first one is the lowest) contrary to \n"
    "the common convention for image data.\n"
    "Initially the pixel width and heigt will be 1 micron and the data range will be 0 to 1.0 (black to white level). \n"
    "To adjust the data range use the \\min_value and \\max_value properties.\n"
    "\n"
    "@param w The width of the image\n"
    "@param h The height of the image\n"
    "@param red The red channel data set which will become owned by the image\n"
    "@param green The green channel data set which will become owned by the image\n"
    "@param blue The blue channel data set which will become owned by the image\n"
  ) +
  gsi::constructor ("new", &gsi::new_image_whtrgb,
    "@brief Constructor for a color image with the given pixel values\n"
    "@args w, h, trans, red, green, blue\n"
    "\n"
    "This constructor creates an image from the given pixel values. The values have to be organized\n"
    "line by line and separated by color channel. Each line must consist of \"w\" values where the first value is the leftmost pixel.\n"
    "Note, that the rows are oriented in the mathematical sense (first one is the lowest) contrary to \n"
    "the common convention for image data.\n"
    "Initially the pixel width and heigt will be 1 micron and the data range will be 0 to 1.0 (black to white level). \n"
    "To adjust the data range use the \\min_value and \\max_value properties.\n"
    "\n"
    "@param w The width of the image\n"
    "@param h The height of the image\n"
    "@param trans The transformation from pixel space to micron space\n"
    "@param red The red channel data set which will become owned by the image\n"
    "@param green The green channel data set which will become owned by the image\n"
    "@param blue The blue channel data set which will become owned by the image\n"
  ) +
  gsi::method ("box", &img::Object::box,
    "@brief Get the bounding box of the image\n"
    "@return The bounding box\n"
  ) +
  gsi::method ("transformed", &img::Object::transformed<db::DTrans>,
    "@brief Transform the image with the given simple transformation\n"
    "@args t\n"
    "@param t The transformation to apply\n"
    "@return The transformed object\n"
  ) +
  gsi::method ("transformed_matrix|transformed", &img::Object::transformed<db::Matrix3d>,
    "@brief Transform the image with the given matrix transformation\n"
    "@args t\n"
    "@param t The transformation to apply (a matrix)\n"
    "@return The transformed object\n"
    "This method has been introduced in version 0.22."
  ) +
  gsi::method ("transformed_cplx|transformed", &img::Object::transformed<db::DCplxTrans>,
    "@brief Transform the image with the given complex transformation\n"
    "@args t\n"
    "@param t The magnifying transformation to apply\n"
    "@return The transformed object\n"
  ) +
  gsi::method ("width", &img::Object::width,
    "@brief Get the width of the image in pixels\n"
    "@return The width in pixels\n"
  ) +
  gsi::method ("height", &img::Object::height,
    "@brief Get the height of the image in pixels\n"
    "@return The height in pixels\n"
  ) +
  gsi::method ("filename", &img::Object::filename,
    "@brief Get the name of the file loaded of an empty string if not file is loaded\n"
    "@return The file name (path)\n"
  ) +
  gsi::method ("is_empty?", &img::Object::is_empty,
    "@brief Returns true, if the image does not contain any data (i.e. is default constructed)\n"
    "@return True, if the image is empty\n"
  ) +
  gsi::method ("is_color?", &img::Object::is_color,
    "@brief Returns true, if the image is a color image\n"
    "@return True, if the image is a color image\n"
  ) +
  gsi::method ("set_mask", &img::Object::set_mask,
    "@brief Set the mask for a pixel\n"
    "@args x, y, m\n"
    "\n"
    "@param x The x coordinate of the pixel (0..width()-1)\n"
    "@param y The y coordinate of the pixel (mathematical order: 0 is the lowest, 0..height()-1)\n"
    "@param m The mask\n"
    "\n"
    "If the mask of a pixel is set to false, the pixel is not drawn. The default is true for all pixels.\n"
    "\n"
    "This method has been introduced in version 0.23.\n"
  ) +
  gsi::method ("mask", (bool (img::Object::*) (size_t x, size_t y) const) &img::Object::mask,
    "@brief Gets the mask for one pixel\n"
    "@args x, y\n"
    "\n"
    "@param x The x coordinate of the pixel (0..width()-1)\n"
    "@param y The y coordinate of the pixel (mathematical order: 0 is the lowest, 0..height()-1)\n"
    "@return false if the pixel is not drawn.\n"
    "\n"
    "See \\set_mask for details about the mask.\n"
    "\n"
    "This method has been introduced in version 0.23.\n"
  ) +
  gsi::method ("set_pixel", (void (img::Object::*)(size_t x, size_t y, double v)) &img::Object::set_pixel,
    "@brief Set one pixel (monochrome)\n"
    "@args x, y, v\n"
    "\n"
    "@param x The x coordinate of the pixel (0..width()-1)\n"
    "@param y The y coordinate of the pixel (mathematical order: 0 is the lowest, 0..height()-1)\n"
    "@param v The value\n"
    "\n"
    "If the component index, x or y value exceeds the image bounds of the image is a color image,\n"
    "this method does nothing.\n"
  ) +
  gsi::method ("set_pixel", (void (img::Object::*)(size_t x, size_t y, double r, double g, double b)) &img::Object::set_pixel,
    "@brief Set one pixel (color)\n"
    "@args x, y, r, g, b\n"
    "\n"
    "@param x The x coordinate of the pixel (0..width()-1)\n"
    "@param y The y coordinate of the pixel (mathematical order: 0 is the lowest, 0..height()-1)\n"
    "@param red The red component\n"
    "@param green The green component\n"
    "@param blue The blue component\n"
    "\n"
    "If the component index, x or y value exceeds the image bounds of the image is not a color image,\n"
    "this method does nothing.\n"
  ) +
  gsi::method ("get_pixel", (double (img::Object::*)(size_t x, size_t y) const) &img::Object::pixel,
    "@brief Accessor to one pixel (monochrome and color)\n"
    "@args x, y\n"
    "\n"
    "@param x The x coordinate of the pixel (0..width()-1)\n"
    "@param y The y coordinate of the pixel (mathematical order: 0 is the lowest, 0..height()-1)\n"
    "@param component 0 for red, 1 for green, 2 for blue.\n"
    "\n"
    "If the component index, x or y value exceeds the image bounds, this method \n"
    "returns 0.0. For monochrome images, the component index is ignored.\n"
  ) +
  gsi::method ("get_pixel", (double (img::Object::*)(size_t x, size_t y, unsigned int component) const) &img::Object::pixel,
    "@brief Accessor to one pixel (monochrome and color)\n"
    "@args x, y, component\n"
    "\n"
    "@param x The x coordinate of the pixel (0..width()-1)\n"
    "@param y The y coordinate of the pixel (mathematical order: 0 is the lowest, 0..height()-1)\n"
    "@param component 0 for red, 1 for green, 2 for blue.\n"
    "\n"
    "If the component index, x or y value exceeds the image bounds, this method \n"
    "returns 0.0. For monochrome images, the component index is ignored.\n"
  ) +
  gsi::method ("set_data", (void (img::Object::*)(size_t w, size_t h, const std::vector<double> &d)) &img::Object::set_data,
    "@brief Write the image data field (monochrome)\n"
    "@args w, h, d\n"
    "@param w The width of the new data\n"
    "@param h The height of the new data\n"
    "@param d The (monochrome) data to load into the image\n"
    "\n"
    "See the constructor description for the data organisation in that field.\n"
  ) +
  gsi::method ("set_data", (void (img::Object::*)(size_t w, size_t h, const std::vector<double> &r, const std::vector<double> &g, const std::vector<double> &b)) &img::Object::set_data,
    "@brief Write the image data field (color)\n"
    "@args w, h, r, g, b\n"
    "@param w The width of the new data\n"
    "@param h The height of the new data\n"
    "@param r The red channel data to load into the image\n"
    "@param g The green channel data to load into the image\n"
    "@param b The blue channel data to load into the image\n"
    "\n"
    "See the constructor description for the data organisation in that field.\n"
  ) +
  gsi::method_ext ("pixel_width=", &img_set_pixel_width,
    "@brief Set the pixel width\n"
    "@args w\n"
    "\n"
    "The pixel width determines the width of on pixel in the original space which is transformed to\n"
    "micron space with the transformation.\n"
    "\n"
    "Starting with version 0.22, this property is incorporated into the transformation matrix.\n"
    "This property is provided for convenience only."
  ) +
  gsi::method_ext ("pixel_width", &img_get_pixel_width,
    "@brief Get the pixel width\n"
    "\n"
    "See \\pixel_width= for a description of that property.\n"
    "\n"
    "Starting with version 0.22, this property is incorporated into the transformation matrix.\n"
    "This property is provided for convenience only."
  ) +
  gsi::method_ext ("pixel_height=", &img_set_pixel_height,
    "@brief Set the pixel height\n"
    "@args h\n"
    "\n"
    "The pixel height determines the height of on pixel in the original space which is transformed to\n"
    "micron space with the transformation.\n"
    "\n"
    "Starting with version 0.22, this property is incorporated into the transformation matrix.\n"
    "This property is provided for convenience only."
  ) +
  gsi::method_ext ("pixel_height", &img_get_pixel_height,
    "@brief Get the pixel height\n"
    "\n"
    "See \\pixel_height= for a description of that property.\n"
    "\n"
    "Starting with version 0.22, this property is incorporated into the transformation matrix.\n"
    "This property is provided for convenience only."
  ) +
  gsi::method ("matrix=", &img::Object::set_matrix,
    "@brief Set the transformation matrix\n"
    "@args t\n"
    "\n"
    "This transformation matrix converts pixel coordinates (0,0 being the center and each pixel having the dimension of pixel_width and pixel_height)\n"
    "to micron coordinates. The coordinate of the pixel is the lower left corner of the pixel.\n"
    "\n"
    "The matrix is more general than the transformation used before and supports shear and perspective transformation. This property replaces the \\trans property which is "
    "still functional, but deprecated.\n"
    "\n"
    "This method has been introduced in version 0.22."
  ) +
  gsi::method ("matrix", &img::Object::matrix,
    "@brief Return the pixel-to-micron transformation matrix\n"
    "\n"
    "This transformation matrix converts pixel coordinates (0,0 being the center and each pixel having the dimension of pixel_width and pixel_height)\n"
    "to micron coordinates. The coordinate of the pixel is the lower left corner of the pixel.\n"
    "\n"
    "The matrix is more general than the transformation used before and supports shear and perspective transformation. This property replaces the \\trans property which is "
    "still functional, but deprecated.\n"
    "\n"
    "This method has been introduced in version 0.22."
  ) +
  gsi::method_ext ("trans", &img_get_trans,
    "@brief Return the pixel-to-micron transformation\n"
    "\n"
    "This transformation converts pixel coordinates (0,0 being the lower left corner and each pixel having the dimension of pixel_width and pixel_height)\n"
    "to micron coordinates. The coordinate of the pixel is the lower left corner of the pixel.\n"
    "\n"
    "The general property is \\matrix which also allows perspective and shear transformation. This property will only "
    "work, if the transformation does not include perspective or shear components. Therefore this property is deprecated."
    "\n"
    "Please note that for backward compatibility, the rotation center is pixel 0,0 (lowest left one), while it "
    "is the image center for the matrix transformation."
  ) +
  gsi::method_ext ("trans=", &img_set_trans,
    "@brief Set the transformation\n"
    "@args t\n"
    "\n"
    "This transformation converts pixel coordinates (0,0 being the lower left corner and each pixel having the dimension of pixel_width and pixel_height)\n"
    "to micron coordinates. The coordinate of the pixel is the lower left corner of the pixel.\n"
    "\n"
    "The general property is \\matrix which also allows perspective and shear transformation."
    "\n"
    "Please note that for backward compatibility, the rotation center is pixel 0,0 (lowest left one), while it "
    "is the image center for the matrix transformation."
  ) +
  gsi::method ("min_value=", &img::Object::set_min_value,
    "@brief Set the minimum value\n"
    "@args v\n"
    "\n"
    "See \\min_value for the description of the minimum value property.\n"
  ) +
  gsi::method ("min_value", &img::Object::min_value,
    "@brief Get the upper limit of the values in the data set\n"
    "\n"
    "This value determines the upper end of the data mapping (i.e. white value etc.).\n"
    "It does not necessarily correspond to the minimum value of the data set but it must be\n"
    "larger than that.\n"
  ) +
  gsi::method ("max_value=", &img::Object::set_max_value,
    "@brief Get the upper limit of the values in the data set\n"
    "@args v\n"
    "\n"
    "This value determines the upper end of the data mapping (i.e. white value etc.).\n"
    "It does not necessarily correspond to the maximum value of the data set but it must be\n"
    "larger than that.\n"
  ) +
  gsi::method ("max_value", &img::Object::max_value,
    "@brief Set the maximum value\n"
    "\n"
    "See the \\max_value method for the description of the maximum value property.\n"
  ) +
  gsi::method ("visible=", &img::Object::set_visible,
    "@brief Set the visibility\n"
    "@args v\n"
    "\n"
    "See the \\is_visible? method for a description of this property.\n"
    "\n"
    "This method has been introduced in version 0.20.\n"
  ) +
  gsi::method ("is_visible?", &img::Object::is_visible,
    "@brief Gets a flag indicating whether the image object is visible\n"
    "\n"
    "An image object can be made invisible by setting the visible property to false.\n"
    "\n"
    "This method has been introduced in version 0.20.\n"
  ) +
  gsi::method ("id", (int (img::Object::*) () const) &img::Object::id,
    "@brief Get the Id\n"
    "\n"
    "The Id is an arbitrary integer that can be used to track the evolution of an\n"
    "image object. The Id is not changed when the object is edited.\n"
    "On initialization, a unique Id is given to the object. The Id cannot be changed. "
    "This behaviour has been modified in version 0.20."
  ) +
  gsi::method ("data_mapping=", &img::Object::set_data_mapping,
    "@brief Set the data mapping object\n"
    "@args data_mapping\n"
    "\n"
    "The data mapping describes the transformation of a pixel value (any double value) into pixel data "
    "which can be sent to the graphics cards for display. See \\ImageDataMapping for a more detailed description.\n"
  ) +
  gsi::method ("data_mapping", &img::Object::data_mapping,
    "@brief Get the data mapping\n"
    "@return The data mapping object\n"
    "\n"
    "The data mapping describes the transformation of a pixel value (any double value) into pixel data "
    "which can be sent to the graphics cards for display. See \\ImageDataMapping for a more detailed description.\n"
  ) +
  gsi::method ("to_s", &img::Object::to_string,
    "@brief Conver the image to a string\n"
    "@return The string\n"
  ),
  "@brief An image to be stored as a layout annotation\n"
  "\n"
  "Images can be put onto the layout canvas as annotations, along with rulers and markers.\n"
  "Images can be monochrome (represent scalar data) as well as color (represent color images).\n"
  "The display of images can be adjusted in various ways, i.e. color mapping (translation of scalar values to\n"
  "colors), geometrical transformations (including rotation by arbitrary angles) and similar.\n"
  "Images are always based on floating point data. The actual data range is not fixed and can be adjusted to "
  "the data set (i.e. 0..255 or -1..1). This gives a great flexibility when displaying data which is the result of "
  "some measurement or calculation for example.\n"
  "The basic parameters of an image are the width and height of the data set, the width and height of one pixel, "
  "the geometrical transformation to be applied, the data range (min_value to max_value) and the data mapping which "
  "is described by an own class, \\ImageDataMapping.\n"
  "\n"
  "Starting with version 0.22, the basic transformation is a 3x3 matrix rather than the simple "
  "affine transformation. This matrix includes the pixel dimensions as well. One consequence of that is "
  "that the magnification part of the matrix and the pixel dimensions are no longer separated. "
  "That has certain consequences, i.e. setting an affine transformation with a magnification scales "
  "the pixel sizes as before but an affine transformation returned will no longer contain the pixel dimensions "
  "as magnification because it only supports isotropic scaling. For backward compatibility, the rotation "
  "center for the affine transformations while the default center and the center for matrix transformations "
  "is the image center."
);

static void clear_images (lay::LayoutView *view)
{
  img::Service *img_service = view->get_plugin <img::Service> ();
  if (img_service) {
    img_service->clear_images ();
  }
}

static void show_image (lay::LayoutView *view, size_t id, bool visible)
{
  img::Service *img_service = view->get_plugin <img::Service> ();
  if (img_service) {

    const img::Object *img = img_service->object_by_id (id);
    if (img == 0) {
      throw tl::Exception (tl::to_string (QObject::tr ("The image Id is not valid")));
    }

    img::Object new_img (*img);
    new_img.set_visible (visible);

    img_service->change_image_by_id (id, new_img);

  }
}

static void replace_image (lay::LayoutView *view, size_t id, img::Object &new_obj)
{
  img::Service *img_service = view->get_plugin <img::Service> ();
  if (img_service) {

    const img::Object *img = img_service->object_by_id (id);
    if (img == 0) {
      throw tl::Exception (tl::to_string (QObject::tr ("The image Id is not valid")));
    }

    img_service->change_image_by_id (id, new_obj);

  }
}

static void erase_image (lay::LayoutView *view, size_t id)
{
  img::Service *img_service = view->get_plugin <img::Service> ();
  if (img_service) {

    const img::Object *img = img_service->object_by_id (id);
    if (img == 0) {
      throw tl::Exception (tl::to_string (QObject::tr ("The image Id is not valid")));
    }

    img_service->erase_image_by_id (id);

  }
}

static void insert_image (lay::LayoutView *view, const img::Object &obj)
{
  img::Service *img_service = view->get_plugin <img::Service> ();
  if (img_service) {
    img_service->insert_image (obj);
  }
}

static img::ImageIterator begin_images (lay::LayoutView *view)
{
  img::Service *img_service = view->get_plugin <img::Service> ();
  if (img_service) {
    return img_service->begin_images ();
  } else {
    return img::ImageIterator ();
  }
}

static
gsi::ClassExt<lay::LayoutView> layout_view_decl (
  gsi::method_ext ("clear_images", &gsi::clear_images, 
    "@brief Clear all images on this view"
  ) +
  gsi::method_ext ("replace_image", &gsi::replace_image, 
    "@brief Replace an image object with the new image\n"
    "\n"
    "@args id, new_obj\n"
    "@param id The id of the object to replace\n"
    "@param new_obj The new object to replace the old one\n"
    "\n"
    "Replaces  the image with the given Id with the new object. The Id can be obtained with if \"id\" method of the image object.\n"
    "\n"
    "This method has been introduced in version 0.20.\n"
  ) +
  gsi::method_ext ("erase_image", &gsi::erase_image, 
    "@brief Erase the given image\n"
    "@args id\n"
    "@param id The id of the object to erase\n"
    "\n"
    "Erases the image with the given Id. The Id can be obtained with if \"id\" method of the image object.\n"
    "\n"
    "This method has been introduced in version 0.20.\n"
  ) +
  gsi::method_ext ("show_image", &gsi::show_image, 
    "@brief Shows or hides the given image\n"
    "@args id, visible\n"
    "@param id The id of the object to show or hide\n"
    "@param visible True, if the image should be shown\n"
    "\n"
    "Sets the visibility of the image with the given Id. The Id can be obtained with if \"id\" method of the image object.\n"
    "\n"
    "This method has been introduced in version 0.20.\n"
  ) +
  gsi::method_ext ("insert_image", &gsi::insert_image, 
    "@brief Insert an image object into the given view\n"
    "@args obj\n"
    "Insert the image object given by obj into the view. "
  ) +
  gsi::iterator_ext ("each_image", &gsi::begin_images, 
    "@brief Iterate over all images attached to this view"
  ),
  ""
);

class SelectionIterator 
{
public:
  typedef img::Object value_type;
  typedef std::map<img::Service::obj_iterator, unsigned int>::const_iterator iterator_type;
  typedef void pointer; 
  typedef const value_type &reference;
  typedef std::forward_iterator_tag iterator_category;
  typedef void difference_type;

  SelectionIterator (const std::vector<img::Service *> &services) 
    : m_services (services), m_service (0)
  {
    if (! m_services.empty ()) {
      m_iter = m_services [m_service]->selection ().begin ();
      next ();
    }
  }

  bool at_end () const
  {
    return (m_service >= m_services.size ());
  }

  SelectionIterator &operator++ ()
  {
    ++m_iter;
    next ();
    return *this;
  }

  const value_type &operator* () const
  {
    return *(dynamic_cast<const img::Object *> (m_iter->first->ptr ()));
  }

private:
  std::vector<img::Service *> m_services;
  unsigned int m_service;
  iterator_type m_iter;

  void next ()
  {
    while (m_iter == m_services [m_service]->selection ().end ()) {
      ++m_service;
      if (m_service < m_services.size ()) {
        m_iter = m_services [m_service]->selection ().begin ();
      } else {
        break;
      }
    }
  }
};

//  extend the layout view by "edtService" specific methods 

static bool has_image_selection (const lay::LayoutView *view)
{
  std::vector<img::Service *> img = view->get_plugins <img::Service> ();
  for (std::vector<img::Service *>::const_iterator s = img.begin (); s != img.end (); ++s) {
    if ((*s)->selection_size () > 0) {
      return true;
    }
  }
  return false;
}

static SelectionIterator begin_images_selected (const lay::LayoutView *view)
{
  return SelectionIterator (view->get_plugins <img::Service> ());
}


static
gsi::ClassExt<lay::LayoutView> layout_view_decl2 (
  gsi::method_ext ("has_image_selection?", &has_image_selection, 
    "@brief Returns true, if images are selected in this view"
    "\n"
    "This method was introduced in version 0.19."
  ) +
  gsi::iterator_ext ("each_image_selected", &begin_images_selected,
    "@brief Iterate over each selected image object, yielding a \\Image object for each of them"
    "\n"
    "This method was introduced in version 0.19."
  ),
  ""
);

}

