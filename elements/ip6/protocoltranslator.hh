#ifndef PROTOCOLTRANSLATOR_HH
#define PROTOCOLTRANSLATOR_HH

#include <click/ip6address.hh>
#include <click/ipaddress.hh>
#include <click/vector.hh>
#include <click/element.hh>

/*
 * =c
 * ProtocolTranslator()
 *
 *
 * =s IPv6
 * translate IP/ICMP, TCP, and UDP packets between IPv4 and IPv6 protocols
 *
 * =d
 *
 * 
 * Has two inputs and two outputs. Input packets are valid IPv6 packets or 
 * IPv4 packets.  IPv4 packets will be translated to IPv6 packets.  IPv6 
 * packets will be translated to IPv4 packets.  Output packets are valid 
 * IPv4/v6 packets; for instance, translated packets have their IP, ICMP/ICMPv6, 
 * TCP and/or UDP checksums updated.
 *
 * 
 * =a AddressTranslator */

class ProtocolTranslator : public Element {
  
  
 public:
  
  ProtocolTranslator();
  ~ProtocolTranslator();
  
  const char *class_name() const		{ return "ProtocolTranslator"; }
  const char *processing() const	{ return AGNOSTIC; }
  ProtocolTranslator *clone() const { return new ProtocolTranslator; }
  int configure(const Vector<String> &, ErrorHandler *);
  void push(int port, Packet *p);
  void handle_ip6(Packet *);
  void handle_ip4(Packet *);
 
private:

  Packet * make_icmp_translate64(unsigned char *a,
				unsigned char payload_length);

  Packet * make_icmp_translate46(IP6Address ip6_src,
				 IP6Address ip6_dst,
				 unsigned char *a,
				 unsigned char payload_length);
  
  Packet * make_translate64(IPAddress src,
			    IPAddress dst,
			    click_ip6 * ip6,
			    unsigned char *a); 

  Packet * make_translate46(IP6Address src, 
			    IP6Address dst,
			    click_ip * ip,
			    unsigned char *a);

};
		   

#endif
