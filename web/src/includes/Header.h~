#ifndef HEADER_H
#define HEADER_H

class Header{
public:
   Header();
#if 0   
   char req_type;
   char file_requested;
   char user_agert;
   char host;
   char content_type;
   char acc_encoding;
   char connection_type;
#endif

   void extractor(char *buffer);
   ~Header();
private:
   enum class m_method{
      GET,
      POST
   };
   enum class headers{
      h_method,
      h_path,
      h_protocol,
      h_name,
      h_value
   };

};




#endif
