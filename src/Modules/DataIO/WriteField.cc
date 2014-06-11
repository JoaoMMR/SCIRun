/*
   For more information, please see: http://software.sci.utah.edu

   The MIT License

   Copyright (c) 2009 Scientific Computing and Imaging Institute,
   University of Utah.

   
   Permission is hereby granted, free of charge, to any person obtaining a
   copy of this software and associated documentation files (the "Software"),
   to deal in the Software without restriction, including without limitation
   the rights to use, copy, modify, merge, publish, distribute, sublicense,
   and/or sell copies of the Software, and to permit persons to whom the
   Software is furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included
   in all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
   OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
   THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
   FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
   DEALINGS IN THE SOFTWARE.
*/
/// @todo Documentation Modules/DataIO/WriteField.cc


///
///@file  WriteField.cc
///@brief Save persistent representation of a field to a file
///
///@author
///   Elisha R. Hughes
///   CVRTI
///   University of Utah
///  based on:
///   Steven G. Parker
///   Department of Computer Science
///   University of Utah
///   July 1994
///
///@date November 2004
///

#include <Modules/DataIO/WriteField.h>
#include <Core/Datatypes/Legacy/Field/Field.h>
#include <Core/ImportExport/Field/FieldIEPlugin.h>
#include <Core/Algorithms/Base/AlgorithmVariableNames.h>
#include <Core/Logging/Log.h>

using namespace SCIRun::Core::Algorithms;
using namespace SCIRun::Modules::DataIO;

WriteFieldModule::WriteFieldModule()
  : my_base("WriteField", "DataIO", "SCIRun", "Filename")    
    //gui_types_(get_ctx()->subVar("types", false)),
    //gui_exporttype_(get_ctx()->subVar("exporttype"), ""),
    //gui_increment_(get_ctx()->subVar("increment"), 0),
    //gui_current_(get_ctx()->subVar("current"), 0)
{
  INITIALIZE_PORT(FieldToWrite);
  filetype_ = "Binary";
  objectPortName_ = &FieldToWrite;

  FieldIEPluginManager mgr;
  auto types = makeGuiTypesListForExport(mgr);
  get_state()->setValue(Variables::FileTypeList, types);

#ifdef SCIRUN4_CODE_TO_BE_ENABLED_LATER
  FieldIEPluginManager mgr;
  std::vector<std::string> exporters;
  mgr.get_exporter_list(exporters);
  
  std::string exporttypes = "{";
  exporttypes += "{{SCIRun Field Binary} {.fld} } ";
  exporttypes += "{{SCIRun Field ASCII} {.fld} } ";

  for (unsigned int i = 0; i < exporters.size(); i++)
  {
    FieldIEPlugin *pl = mgr.get_plugin(exporters[i]);
    if (pl->fileextension != "")
    {
      exporttypes += "{{" + exporters[i] + "} {" + pl->fileextension + "} } ";
    }
    else
    {
      exporttypes += "{{" + exporters[i] + "} {.*} } ";
    }
  }

  exporttypes += "}";

  gui_types_.set(exporttypes);
#endif
}

bool WriteFieldModule::call_exporter(const std::string &filename)
{
  return false;
  /*
  const std::string ftpre = gui_exporttype_.get();
  const std::string::size_type loc = ftpre.find(" (");
  const std::string ft = ftpre.substr(0, loc);
  
  FieldIEPluginManager mgr;
  FieldIEPlugin *pl = mgr.get_plugin(ft);
  if (pl)
  {
    return pl->filewriter(this, handle_, filename.c_str());
  }
  return false;
  */
}

void WriteFieldModule::execute()
{
#ifdef SCIRUN4_CODE_TO_BE_ENABLED_LATER
  const std::string ftpre = gui_exporttype_.get();
  const std::string::size_type loc = ftpre.find(" (");
  const std::string ft = ftpre.substr(0, loc);

 
  
  //get the current file name
  const std::string oldfilename=filename_.get();
  
  //determine if we should increment an index in the file name
  if (gui_increment_.get()) 
  {

    //warn the user if they try to use 'Increment' incorrectly	
    const std::string::size_type loc2 = oldfilename.find("%d");
    if(loc2 == std::string::npos) 
    {
      remark("To use the increment function, there must be a '%d' in the file name.");
    }
    
    char buf[1024];
   
    int current=gui_current_.get();
    sprintf(buf, filename_.get().c_str(), current);
    
    filename_.set(buf);
    gui_current_.set(current+1);
  }
#endif

  my_base::execute();

#ifdef SCIRUN4_CODE_TO_BE_ENABLED_LATER
   if (gui_increment_.get())
    filename_.set(oldfilename);
#endif

}

bool WriteFieldModule::useCustomExporter(const std::string& filename) const 
{
  auto ft = get_state()->getValue(Variables::FileTypeName).getString();
  LOG_DEBUG("WriteField with filetype " << ft);
  
  filetype_ = (ft == "SCIRun Field ASCII") ? "ASCII" : "Binary";

  return !(ft == "" ||
    ft == "SCIRun Field Binary" ||
    ft == "SCIRun Field ASCII" ||
    ft == "Binary");
}