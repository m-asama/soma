/**
 * @file	config_model_build_description.cpp
 * @brief	設定モデル説明文初期化関数実装
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "config_model_build.h"
#include "config_model_node.h"
#include "config_model_nodes.h"

void
config_model_build_description()
{
	config_model_node *t;

	t = cmn_interfaces;
	t->description_ja("interfaces");
	t->description_en("interfaces");

	t = cmn_interfaces_interface_;
	t->description_ja("interface");
	t->description_en("interface");

	t = cmn_interfaces_interface__name;
	t->description_ja("name");
	t->description_en("name");

	t = cmn_interfaces_interface__description;
	t->description_ja("description");
	t->description_en("description");

	t = cmn_interfaces_interface__type;
	t->description_ja("type");
	t->description_en("type");

	t = cmn_interfaces_interface__enabled;
	t->description_ja("enabled");
	t->description_en("enabled");

	t = cmn_interfaces_interface__link_up_down_trap_enable;
	t->description_ja("link-up-down-trap-enable");
	t->description_en("link-up-down-trap-enable");

	t = cmn_interfaces_interface__ipv4;
	t->description_ja("ipv4");
	t->description_en("ipv4");

	t = cmn_interfaces_interface__ipv4_enabled;
	t->description_ja("enabled");
	t->description_en("enabled");

	t = cmn_interfaces_interface__ipv4_forwarding;
	t->description_ja("forwarding");
	t->description_en("forwarding");

	t = cmn_interfaces_interface__ipv4_mtu;
	t->description_ja("mtu");
	t->description_en("mtu");

	t = cmn_interfaces_interface__ipv4_address_;
	t->description_ja("address");
	t->description_en("address");

	t = cmn_interfaces_interface__ipv4_address__ip;
	t->description_ja("ip");
	t->description_en("ip");

	t = cmn_interfaces_interface__ipv4_address__prefix_length;
	t->description_ja("prefix-length");
	t->description_en("prefix-length");

	t = cmn_interfaces_interface__ipv4_address__netmask;
	t->description_ja("netmask");
	t->description_en("netmask");

	t = cmn_interfaces_interface__ipv4_neighbor_;
	t->description_ja("neighbor");
	t->description_en("neighbor");

	t = cmn_interfaces_interface__ipv4_neighbor__ip;
	t->description_ja("ip");
	t->description_en("ip");

	t = cmn_interfaces_interface__ipv4_neighbor__link_layer_address;
	t->description_ja("link-layer-address");
	t->description_en("link-layer-address");

	t = cmn_interfaces_interface__ipv6;
	t->description_ja("ipv6");
	t->description_en("ipv6");

	t = cmn_interfaces_interface__ipv6_enabled;
	t->description_ja("enabled");
	t->description_en("enabled");

	t = cmn_interfaces_interface__ipv6_forwarding;
	t->description_ja("forwarding");
	t->description_en("forwarding");

	t = cmn_interfaces_interface__ipv6_mtu;
	t->description_ja("mtu");
	t->description_en("mtu");

	t = cmn_interfaces_interface__ipv6_address_;
	t->description_ja("address");
	t->description_en("address");

	t = cmn_interfaces_interface__ipv6_address__ip;
	t->description_ja("ip");
	t->description_en("ip");

	t = cmn_interfaces_interface__ipv6_address__prefix_length;
	t->description_ja("prefix-length");
	t->description_en("prefix-length");

	t = cmn_interfaces_interface__ipv6_neighbor_;
	t->description_ja("neighbor");
	t->description_en("neighbor");

	t = cmn_interfaces_interface__ipv6_neighbor__ip;
	t->description_ja("ip");
	t->description_en("ip");

	t = cmn_interfaces_interface__ipv6_neighbor__link_layer_address;
	t->description_ja("link-layer-address");
	t->description_en("link-layer-address");

	t = cmn_interfaces_interface__ipv6_dup_addr_detect_transmits;
	t->description_ja("dup-addr-detect-transmits");
	t->description_en("dup-addr-detect-transmits");

	t = cmn_interfaces_interface__ipv6_autoconf;
	t->description_ja("autoconf");
	t->description_en("autoconf");

	t = cmn_interfaces_interface__ipv6_autoconf_create_global_addresses;
	t->description_ja("create-global-addresses");
	t->description_en("create-global-addresses");

	t = cmn_interfaces_interface__ipv6_autoconf_create_temporary_addresses;
	t->description_ja("create-temporary-addresses");
	t->description_en("create-temporary-addresses");

	t = cmn_interfaces_interface__ipv6_autoconf_temporary_valid_lifetime;
	t->description_ja("temporary-valid-lifetime");
	t->description_en("temporary-valid-lifetime");

	t = cmn_interfaces_interface__ipv6_autoconf_temporary_preferred_lifetime;
	t->description_ja("temporary-preferred-lifetime");
	t->description_en("temporary-preferred-lifetime");

	t = cmn_interfaces_state;
	t->description_ja("interfaces-state");
	t->description_en("interfaces-state");

	t = cmn_interfaces_state_interface_;
	t->description_ja("interface");
	t->description_en("interface");

	t = cmn_interfaces_state_interface__name;
	t->description_ja("name");
	t->description_en("name");

	t = cmn_interfaces_state_interface__type;
	t->description_ja("type");
	t->description_en("type");

	t = cmn_interfaces_state_interface__admin_status;
	t->description_ja("admin-status");
	t->description_en("admin-status");

	t = cmn_interfaces_state_interface__oper_status;
	t->description_ja("oper-status");
	t->description_en("oper-status");

	t = cmn_interfaces_state_interface__last_change;
	t->description_ja("last-change");
	t->description_en("last-change");

	t = cmn_interfaces_state_interface__if_index;
	t->description_ja("if-index");
	t->description_en("if-index");

	t = cmn_interfaces_state_interface__phys_address;
	t->description_ja("phys-address");
	t->description_en("phys-address");

	t = cmn_interfaces_state_interface__speed;
	t->description_ja("speed");
	t->description_en("speed");

	t = cmn_interfaces_state_interface__statistics;
	t->description_ja("statistics");
	t->description_en("statistics");

	t = cmn_interfaces_state_interface__statistics_discontinuity_time;
	t->description_ja("discontinuity-time");
	t->description_en("discontinuity-time");

	t = cmn_interfaces_state_interface__statistics_in_octets;
	t->description_ja("in-octets");
	t->description_en("in-octets");

	t = cmn_interfaces_state_interface__statistics_in_unicast_pkts;
	t->description_ja("in-unicast-pkts");
	t->description_en("in-unicast-pkts");

	t = cmn_interfaces_state_interface__statistics_in_broadcast_pkts;
	t->description_ja("in-broadcast-pkts");
	t->description_en("in-broadcast-pkts");

	t = cmn_interfaces_state_interface__statistics_in_multicast_pkts;
	t->description_ja("in-multicast-pkts");
	t->description_en("in-multicast-pkts");

	t = cmn_interfaces_state_interface__statistics_in_discards;
	t->description_ja("in-discards");
	t->description_en("in-discards");

	t = cmn_interfaces_state_interface__statistics_in_errors;
	t->description_ja("in-errors");
	t->description_en("in-errors");

	t = cmn_interfaces_state_interface__statistics_in_unknown_protos;
	t->description_ja("in-unknown-protos");
	t->description_en("in-unknown-protos");

	t = cmn_interfaces_state_interface__statistics_out_octets;
	t->description_ja("out-octets");
	t->description_en("out-octets");

	t = cmn_interfaces_state_interface__statistics_out_unicast_pkts;
	t->description_ja("out-unicast-pkts");
	t->description_en("out-unicast-pkts");

	t = cmn_interfaces_state_interface__statistics_out_broadcast_pkts;
	t->description_ja("out-broadcast-pkts");
	t->description_en("out-broadcast-pkts");

	t = cmn_interfaces_state_interface__statistics_out_multicast_pkts;
	t->description_ja("out-multicast-pkts");
	t->description_en("out-multicast-pkts");

	t = cmn_interfaces_state_interface__statistics_out_discards;
	t->description_ja("out-discards");
	t->description_en("out-discards");

	t = cmn_interfaces_state_interface__statistics_out_errors;
	t->description_ja("out-errors");
	t->description_en("out-errors");

	t = cmn_interfaces_state_interface__ipv4;
	t->description_ja("ipv4");
	t->description_en("ipv4");

	t = cmn_interfaces_state_interface__ipv4_forwarding;
	t->description_ja("forwarding");
	t->description_en("forwarding");

	t = cmn_interfaces_state_interface__ipv4_mtu;
	t->description_ja("mtu");
	t->description_en("mtu");

	t = cmn_interfaces_state_interface__ipv4_address_;
	t->description_ja("address");
	t->description_en("address");

	t = cmn_interfaces_state_interface__ipv4_address__ip;
	t->description_ja("ip");
	t->description_en("ip");

	t = cmn_interfaces_state_interface__ipv4_address__prefix_length;
	t->description_ja("prefix-length");
	t->description_en("prefix-length");

	t = cmn_interfaces_state_interface__ipv4_address__netmask;
	t->description_ja("netmask");
	t->description_en("netmask");

	t = cmn_interfaces_state_interface__ipv4_address__origin;
	t->description_ja("origin");
	t->description_en("origin");

	t = cmn_interfaces_state_interface__ipv4_neighbor_;
	t->description_ja("neighbor");
	t->description_en("neighbor");

	t = cmn_interfaces_state_interface__ipv4_neighbor__ip;
	t->description_ja("ip");
	t->description_en("ip");

	t = cmn_interfaces_state_interface__ipv4_neighbor__link_layer_address;
	t->description_ja("link-layer-address");
	t->description_en("link-layer-address");

	t = cmn_interfaces_state_interface__ipv4_neighbor__origin;
	t->description_ja("origin");
	t->description_en("origin");

	t = cmn_interfaces_state_interface__ipv6;
	t->description_ja("ipv6");
	t->description_en("ipv6");

	t = cmn_interfaces_state_interface__ipv6_forwarding;
	t->description_ja("forwarding");
	t->description_en("forwarding");

	t = cmn_interfaces_state_interface__ipv6_mtu;
	t->description_ja("mtu");
	t->description_en("mtu");

	t = cmn_interfaces_state_interface__ipv6_address_;
	t->description_ja("address");
	t->description_en("address");

	t = cmn_interfaces_state_interface__ipv6_address__ip;
	t->description_ja("ip");
	t->description_en("ip");

	t = cmn_interfaces_state_interface__ipv6_address__prefix_length;
	t->description_ja("prefix-length");
	t->description_en("prefix-length");

	t = cmn_interfaces_state_interface__ipv6_address__origin;
	t->description_ja("origin");
	t->description_en("origin");

	t = cmn_interfaces_state_interface__ipv6_address__status;
	t->description_ja("status");
	t->description_en("status");

	t = cmn_interfaces_state_interface__ipv6_neighbor_;
	t->description_ja("neighbor");
	t->description_en("neighbor");

	t = cmn_interfaces_state_interface__ipv6_neighbor__ip;
	t->description_ja("ip");
	t->description_en("ip");

	t = cmn_interfaces_state_interface__ipv6_neighbor__link_layer_address;
	t->description_ja("link-layer-address");
	t->description_en("link-layer-address");

	t = cmn_interfaces_state_interface__ipv6_neighbor__origin;
	t->description_ja("origin");
	t->description_en("origin");

	t = cmn_interfaces_state_interface__ipv6_neighbor__is_router;
	t->description_ja("is-router");
	t->description_en("is-router");

	t = cmn_interfaces_state_interface__ipv6_neighbor__state;
	t->description_ja("state");
	t->description_en("state");

	t = cmn_routing_state;
	t->description_ja("routing-state");
	t->description_en("routing-state");

	t = cmn_routing_state_routing_instance_;
	t->description_ja("routing-instance");
	t->description_en("routing-instance");

	t = cmn_routing_state_routing_instance__name;
	t->description_ja("name");
	t->description_en("name");

	t = cmn_routing_state_routing_instance__type;
	t->description_ja("type");
	t->description_en("type");

	t = cmn_routing_state_routing_instance__default_ribs;
	t->description_ja("default-ribs");
	t->description_en("default-ribs");

	t = cmn_routing_state_routing_instance__default_ribs_default_rib_;
	t->description_ja("default-rib");
	t->description_en("default-rib");

	t = cmn_routing_state_routing_instance__default_ribs_default_rib__rib_name;
	t->description_ja("rib-name");
	t->description_en("rib-name");

	t = cmn_routing_state_routing_instance__default_ribs_default_rib__address_family;
	t->description_ja("address-family");
	t->description_en("address-family");

	t = cmn_routing_state_routing_instance__interfaces;
	t->description_ja("interfaces");
	t->description_en("interfaces");

	t = cmn_routing_state_routing_instance__interfaces_interface_;
	t->description_ja("interface");
	t->description_en("interface");

	t = cmn_routing_state_routing_instance__interfaces_interface__name;
	t->description_ja("name");
	t->description_en("name");

	t = cmn_routing_state_routing_instance__interfaces_interface__ipv6_router_advertisements;
	t->description_ja("ipv6-router-advertisements");
	t->description_en("ipv6-router-advertisements");

	t = cmn_routing_state_routing_instance__interfaces_interface__ipv6_router_advertisements_send_advertisements;
	t->description_ja("send-advertisements");
	t->description_en("send-advertisements");

	t = cmn_routing_state_routing_instance__interfaces_interface__ipv6_router_advertisements_max_rtr_adv_interval;
	t->description_ja("max-rtr-adv-interval");
	t->description_en("max-rtr-adv-interval");

	t = cmn_routing_state_routing_instance__interfaces_interface__ipv6_router_advertisements_min_rtr_adv_interval;
	t->description_ja("min-rtr-adv-interval");
	t->description_en("min-rtr-adv-interval");

	t = cmn_routing_state_routing_instance__interfaces_interface__ipv6_router_advertisements_managed_flag;
	t->description_ja("managed-flag");
	t->description_en("managed-flag");

	t = cmn_routing_state_routing_instance__interfaces_interface__ipv6_router_advertisements_other_config_flag;
	t->description_ja("other-config-flag");
	t->description_en("other-config-flag");

	t = cmn_routing_state_routing_instance__interfaces_interface__ipv6_router_advertisements_link_mtu;
	t->description_ja("link-mtu");
	t->description_en("link-mtu");

	t = cmn_routing_state_routing_instance__interfaces_interface__ipv6_router_advertisements_reachable_time;
	t->description_ja("reachable-time");
	t->description_en("reachable-time");

	t = cmn_routing_state_routing_instance__interfaces_interface__ipv6_router_advertisements_retrans_timer;
	t->description_ja("retrans-timer");
	t->description_en("retrans-timer");

	t = cmn_routing_state_routing_instance__interfaces_interface__ipv6_router_advertisements_cur_hop_limit;
	t->description_ja("cur-hop-limit");
	t->description_en("cur-hop-limit");

	t = cmn_routing_state_routing_instance__interfaces_interface__ipv6_router_advertisements_default_lifetime;
	t->description_ja("default-lifetime");
	t->description_en("default-lifetime");

	t = cmn_routing_state_routing_instance__interfaces_interface__ipv6_router_advertisements_prefix_list;
	t->description_ja("prefix-list");
	t->description_en("prefix-list");

	t = cmn_routing_state_routing_instance__interfaces_interface__ipv6_router_advertisements_prefix_list_prefix_;
	t->description_ja("prefix");
	t->description_en("prefix");

	t = cmn_routing_state_routing_instance__interfaces_interface__ipv6_router_advertisements_prefix_list_prefix__prefix_spec;
	t->description_ja("prefix-spec");
	t->description_en("prefix-spec");

	t = cmn_routing_state_routing_instance__interfaces_interface__ipv6_router_advertisements_prefix_list_prefix__valid_lifetime;
	t->description_ja("valid-lifetime");
	t->description_en("valid-lifetime");

	t = cmn_routing_state_routing_instance__interfaces_interface__ipv6_router_advertisements_prefix_list_prefix__on_link_flag;
	t->description_ja("on-link-flag");
	t->description_en("on-link-flag");

	t = cmn_routing_state_routing_instance__interfaces_interface__ipv6_router_advertisements_prefix_list_prefix__preferred_lifetime;
	t->description_ja("preferred-lifetime");
	t->description_en("preferred-lifetime");

	t = cmn_routing_state_routing_instance__interfaces_interface__ipv6_router_advertisements_prefix_list_prefix__autonomous_flag;
	t->description_ja("autonomous-flag");
	t->description_en("autonomous-flag");

	t = cmn_routing_state_routing_instance__routing_protocols;
	t->description_ja("routing-protocols");
	t->description_en("routing-protocols");

	t = cmn_routing_state_routing_instance__routing_protocols_routing_protocol_;
	t->description_ja("routing-protocol");
	t->description_en("routing-protocol");

	t = cmn_routing_state_routing_instance__routing_protocols_routing_protocol__type;
	t->description_ja("type");
	t->description_en("type");

	t = cmn_routing_state_routing_instance__routing_protocols_routing_protocol__name;
	t->description_ja("name");
	t->description_en("name");

	t = cmn_routing_state_routing_instance__routing_protocols_routing_protocol__route_preference;
	t->description_ja("route-preference");
	t->description_en("route-preference");

	t = cmn_routing_state_routing_instance__routing_protocols_routing_protocol__connected_ribs;
	t->description_ja("connected-ribs");
	t->description_en("connected-ribs");

	t = cmn_routing_state_routing_instance__routing_protocols_routing_protocol__connected_ribs_connected_rib_;
	t->description_ja("connected-rib");
	t->description_en("connected-rib");

	t = cmn_routing_state_routing_instance__routing_protocols_routing_protocol__connected_ribs_connected_rib__rib_name;
	t->description_ja("rib-name");
	t->description_en("rib-name");

	t = cmn_routing_state_routing_instance__routing_protocols_routing_protocol__connected_ribs_connected_rib__import_filter;
	t->description_ja("import-filter");
	t->description_en("import-filter");

	t = cmn_routing_state_routing_instance__routing_protocols_routing_protocol__connected_ribs_connected_rib__export_filter;
	t->description_ja("export-filter");
	t->description_en("export-filter");

	t = cmn_routing_state_routing_instance__id;
	t->description_ja("id");
	t->description_en("id");

	t = cmn_routing_state_next_hop_lists;
	t->description_ja("next-hop-lists");
	t->description_en("next-hop-lists");

	t = cmn_routing_state_next_hop_lists_next_hop_list_;
	t->description_ja("next-hop-list");
	t->description_en("next-hop-list");

	t = cmn_routing_state_next_hop_lists_next_hop_list__next_hop_;
	t->description_ja("next-hop");
	t->description_en("next-hop");

	t = cmn_routing_state_next_hop_lists_next_hop_list__next_hop__next_hop_list;
	t->description_ja("next-hop-list");
	t->description_en("next-hop-list");

	t = cmn_routing_state_next_hop_lists_next_hop_list__next_hop__use_rib;
	t->description_ja("use-rib");
	t->description_en("use-rib");

	t = cmn_routing_state_next_hop_lists_next_hop_list__next_hop__outgoing_interface;
	t->description_ja("outgoing-interface");
	t->description_en("outgoing-interface");

	t = cmn_routing_state_next_hop_lists_next_hop_list__next_hop__next_hop_address;
	t->description_ja("next-hop-address");
	t->description_en("next-hop-address");

	t = cmn_routing_state_next_hop_lists_next_hop_list__next_hop__next_hop_address;
	t->description_ja("next-hop-address");
	t->description_en("next-hop-address");

	t = cmn_routing_state_next_hop_lists_next_hop_list__next_hop__special_next_hop;
	t->description_ja("special-next-hop");
	t->description_en("special-next-hop");

	t = cmn_routing_state_next_hop_lists_next_hop_list__next_hop__priority;
	t->description_ja("priority");
	t->description_en("priority");

	t = cmn_routing_state_next_hop_lists_next_hop_list__next_hop__weight;
	t->description_ja("weight");
	t->description_en("weight");

	t = cmn_routing_state_next_hop_lists_next_hop_list__id;
	t->description_ja("id");
	t->description_en("id");

	t = cmn_routing_state_next_hop_lists_next_hop_list__address_family;
	t->description_ja("address-family");
	t->description_en("address-family");

	t = cmn_routing_state_ribs;
	t->description_ja("ribs");
	t->description_en("ribs");

	t = cmn_routing_state_ribs_rib_;
	t->description_ja("rib");
	t->description_en("rib");

	t = cmn_routing_state_ribs_rib__name;
	t->description_ja("name");
	t->description_en("name");

	t = cmn_routing_state_ribs_rib__routes;
	t->description_ja("routes");
	t->description_en("routes");

	t = cmn_routing_state_ribs_rib__routes_route_;
	t->description_ja("route");
	t->description_en("route");

	t = cmn_routing_state_ribs_rib__routes_route__route_preference;
	t->description_ja("route-preference");
	t->description_en("route-preference");

	t = cmn_routing_state_ribs_rib__routes_route__next_hop;
	t->description_ja("next-hop");
	t->description_en("next-hop");

	t = cmn_routing_state_ribs_rib__routes_route__next_hop_next_hop_list;
	t->description_ja("next-hop-list");
	t->description_en("next-hop-list");

	t = cmn_routing_state_ribs_rib__routes_route__next_hop_use_rib;
	t->description_ja("use-rib");
	t->description_en("use-rib");

	t = cmn_routing_state_ribs_rib__routes_route__next_hop_outgoing_interface;
	t->description_ja("outgoing-interface");
	t->description_en("outgoing-interface");

	t = cmn_routing_state_ribs_rib__routes_route__next_hop_next_hop_address;
	t->description_ja("next-hop-address");
	t->description_en("next-hop-address");

	t = cmn_routing_state_ribs_rib__routes_route__next_hop_next_hop;
	t->description_ja("next-hop");
	t->description_en("next-hop");

	t = cmn_routing_state_ribs_rib__routes_route__next_hop_special_next_hop;
	t->description_ja("special-next-hop");
	t->description_en("special-next-hop");

	t = cmn_routing_state_ribs_rib__routes_route__source_protocol;
	t->description_ja("source-protocol");
	t->description_en("source-protocol");

	t = cmn_routing_state_ribs_rib__routes_route__active;
	t->description_ja("active");
	t->description_en("active");

	t = cmn_routing_state_ribs_rib__routes_route__last_updated;
	t->description_ja("last-updated");
	t->description_en("last-updated");

	t = cmn_routing_state_ribs_rib__routes_route__destination_prefix;
	t->description_ja("destination-prefix");
	t->description_en("destination-prefix");

	t = cmn_routing_state_ribs_rib__routes_route__destination_prefix;
	t->description_ja("destination-prefix");
	t->description_en("destination-prefix");

	t = cmn_routing_state_ribs_rib__recipient_ribs;
	t->description_ja("recipient-ribs");
	t->description_en("recipient-ribs");

	t = cmn_routing_state_ribs_rib__recipient_ribs_recipient_rib_;
	t->description_ja("recipient-rib");
	t->description_en("recipient-rib");

	t = cmn_routing_state_ribs_rib__recipient_ribs_recipient_rib__rib_name;
	t->description_ja("rib-name");
	t->description_en("rib-name");

	t = cmn_routing_state_ribs_rib__recipient_ribs_recipient_rib__filter;
	t->description_ja("filter");
	t->description_en("filter");

	t = cmn_routing_state_ribs_rib__id;
	t->description_ja("id");
	t->description_en("id");

	t = cmn_routing_state_ribs_rib__address_family;
	t->description_ja("address-family");
	t->description_en("address-family");

	t = cmn_routing_state_route_filters;
	t->description_ja("route-filters");
	t->description_en("route-filters");

	t = cmn_routing_state_route_filters_route_filter_;
	t->description_ja("route-filter");
	t->description_en("route-filter");

	t = cmn_routing_state_route_filters_route_filter__name;
	t->description_ja("name");
	t->description_en("name");

	t = cmn_routing_state_route_filters_route_filter__type;
	t->description_ja("type");
	t->description_en("type");

	t = cmn_routing;
	t->description_ja("routing");
	t->description_en("routing");

	t = cmn_routing_routing_instance_;
	t->description_ja("routing-instance");
	t->description_en("routing-instance");

	t = cmn_routing_routing_instance__name;
	t->description_ja("name");
	t->description_en("name");

	t = cmn_routing_routing_instance__type;
	t->description_ja("type");
	t->description_en("type");

	t = cmn_routing_routing_instance__enabled;
	t->description_ja("enabled");
	t->description_en("enabled");

	t = cmn_routing_routing_instance__description;
	t->description_ja("description");
	t->description_en("description");

	t = cmn_routing_routing_instance__default_ribs;
	t->description_ja("default-ribs");
	t->description_en("default-ribs");

	t = cmn_routing_routing_instance__default_ribs_default_rib_;
	t->description_ja("default-rib");
	t->description_en("default-rib");

	t = cmn_routing_routing_instance__default_ribs_default_rib__rib_name;
	t->description_ja("rib-name");
	t->description_en("rib-name");

	t = cmn_routing_routing_instance__default_ribs_default_rib__address_family;
	t->description_ja("address-family");
	t->description_en("address-family");

	t = cmn_routing_routing_instance__interfaces;
	t->description_ja("interfaces");
	t->description_en("interfaces");

	t = cmn_routing_routing_instance__interfaces_interface_;
	t->description_ja("interface");
	t->description_en("interface");

	t = cmn_routing_routing_instance__interfaces_interface__name;
	t->description_ja("name");
	t->description_en("name");

	t = cmn_routing_routing_instance__interfaces_interface__ipv6_router_advertisements;
	t->description_ja("ipv6-router-advertisements");
	t->description_en("ipv6-router-advertisements");

	t = cmn_routing_routing_instance__interfaces_interface__ipv6_router_advertisements_send_advertisements;
	t->description_ja("send-advertisements");
	t->description_en("send-advertisements");

	t = cmn_routing_routing_instance__interfaces_interface__ipv6_router_advertisements_max_rtr_adv_interval;
	t->description_ja("max-rtr-adv-interval");
	t->description_en("max-rtr-adv-interval");

	t = cmn_routing_routing_instance__interfaces_interface__ipv6_router_advertisements_min_rtr_adv_interval;
	t->description_ja("min-rtr-adv-interval");
	t->description_en("min-rtr-adv-interval");

	t = cmn_routing_routing_instance__interfaces_interface__ipv6_router_advertisements_managed_flag;
	t->description_ja("managed-flag");
	t->description_en("managed-flag");

	t = cmn_routing_routing_instance__interfaces_interface__ipv6_router_advertisements_other_config_flag;
	t->description_ja("other-config-flag");
	t->description_en("other-config-flag");

	t = cmn_routing_routing_instance__interfaces_interface__ipv6_router_advertisements_link_mtu;
	t->description_ja("link-mtu");
	t->description_en("link-mtu");

	t = cmn_routing_routing_instance__interfaces_interface__ipv6_router_advertisements_reachable_time;
	t->description_ja("reachable-time");
	t->description_en("reachable-time");

	t = cmn_routing_routing_instance__interfaces_interface__ipv6_router_advertisements_retrans_timer;
	t->description_ja("retrans-timer");
	t->description_en("retrans-timer");

	t = cmn_routing_routing_instance__interfaces_interface__ipv6_router_advertisements_cur_hop_limit;
	t->description_ja("cur-hop-limit");
	t->description_en("cur-hop-limit");

	t = cmn_routing_routing_instance__interfaces_interface__ipv6_router_advertisements_default_lifetime;
	t->description_ja("default-lifetime");
	t->description_en("default-lifetime");

	t = cmn_routing_routing_instance__interfaces_interface__ipv6_router_advertisements_prefix_list;
	t->description_ja("prefix-list");
	t->description_en("prefix-list");

	t = cmn_routing_routing_instance__interfaces_interface__ipv6_router_advertisements_prefix_list_prefix_;
	t->description_ja("prefix");
	t->description_en("prefix");

	t = cmn_routing_routing_instance__interfaces_interface__ipv6_router_advertisements_prefix_list_prefix__prefix_spec;
	t->description_ja("prefix-spec");
	t->description_en("prefix-spec");

	t = cmn_routing_routing_instance__interfaces_interface__ipv6_router_advertisements_prefix_list_prefix__no_advertise;
	t->description_ja("no-advertise");
	t->description_en("no-advertise");

	t = cmn_routing_routing_instance__interfaces_interface__ipv6_router_advertisements_prefix_list_prefix__valid_lifetime;
	t->description_ja("valid-lifetime");
	t->description_en("valid-lifetime");

	t = cmn_routing_routing_instance__interfaces_interface__ipv6_router_advertisements_prefix_list_prefix__on_link_flag;
	t->description_ja("on-link-flag");
	t->description_en("on-link-flag");

	t = cmn_routing_routing_instance__interfaces_interface__ipv6_router_advertisements_prefix_list_prefix__preferred_lifetime;
	t->description_ja("preferred-lifetime");
	t->description_en("preferred-lifetime");

	t = cmn_routing_routing_instance__interfaces_interface__ipv6_router_advertisements_prefix_list_prefix__autonomous_flag;
	t->description_ja("autonomous-flag");
	t->description_en("autonomous-flag");

	t = cmn_routing_routing_instance__routing_protocols;
	t->description_ja("routing-protocols");
	t->description_en("routing-protocols");

	t = cmn_routing_routing_instance__routing_protocols_routing_protocol_;
	t->description_ja("routing-protocol");
	t->description_en("routing-protocol");

	t = cmn_routing_routing_instance__routing_protocols_routing_protocol__type;
	t->description_ja("type");
	t->description_en("type");

	t = cmn_routing_routing_instance__routing_protocols_routing_protocol__name;
	t->description_ja("name");
	t->description_en("name");

	t = cmn_routing_routing_instance__routing_protocols_routing_protocol__description;
	t->description_ja("description");
	t->description_en("description");

	t = cmn_routing_routing_instance__routing_protocols_routing_protocol__enabled;
	t->description_ja("enabled");
	t->description_en("enabled");

	t = cmn_routing_routing_instance__routing_protocols_routing_protocol__route_preference;
	t->description_ja("route-preference");
	t->description_en("route-preference");

	t = cmn_routing_routing_instance__routing_protocols_routing_protocol__connected_ribs;
	t->description_ja("connected-ribs");
	t->description_en("connected-ribs");

	t = cmn_routing_routing_instance__routing_protocols_routing_protocol__connected_ribs_connected_rib_;
	t->description_ja("connected-rib");
	t->description_en("connected-rib");

	t = cmn_routing_routing_instance__routing_protocols_routing_protocol__connected_ribs_connected_rib__rib_name;
	t->description_ja("rib-name");
	t->description_en("rib-name");

	t = cmn_routing_routing_instance__routing_protocols_routing_protocol__connected_ribs_connected_rib__import_filter;
	t->description_ja("import-filter");
	t->description_en("import-filter");

	t = cmn_routing_routing_instance__routing_protocols_routing_protocol__connected_ribs_connected_rib__export_filter;
	t->description_ja("export-filter");
	t->description_en("export-filter");

	t = cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes;
	t->description_ja("static-routes");
	t->description_en("static-routes");

	t = cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv4;
	t->description_ja("ipv4");
	t->description_en("ipv4");

	t = cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv4_route_;
	t->description_ja("route");
	t->description_en("route");

	t = cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv4_route__destination_prefix;
	t->description_ja("destination-prefix");
	t->description_en("destination-prefix");

	t = cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv4_route__description;
	t->description_ja("description");
	t->description_en("description");

	t = cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv4_route__next_hop;
	t->description_ja("next-hop");
	t->description_en("next-hop");

	t = cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv4_route__next_hop_multipath_entry_;
	t->description_ja("multipath-entry");
	t->description_en("multipath-entry");

	t = cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv4_route__next_hop_multipath_entry__name;
	t->description_ja("name");
	t->description_en("name");

	t = cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv4_route__next_hop_multipath_entry__outgoing_interface;
	t->description_ja("outgoing-interface");
	t->description_en("outgoing-interface");

	t = cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv4_route__next_hop_multipath_entry__next_hop_address;
	t->description_ja("next-hop-address");
	t->description_en("next-hop-address");

	t = cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv4_route__next_hop_multipath_entry__priority;
	t->description_ja("priority");
	t->description_en("priority");

	t = cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv4_route__next_hop_multipath_entry__weight;
	t->description_ja("weight");
	t->description_en("weight");

	t = cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv4_route__next_hop_outgoing_interface;
	t->description_ja("outgoing-interface");
	t->description_en("outgoing-interface");

	t = cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv4_route__next_hop_next_hop_address;
	t->description_ja("next-hop-address");
	t->description_en("next-hop-address");

	t = cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv6;
	t->description_ja("ipv6");
	t->description_en("ipv6");

	t = cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv6_route_;
	t->description_ja("route");
	t->description_en("route");

	t = cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv6_route__destination_prefix;
	t->description_ja("destination-prefix");
	t->description_en("destination-prefix");

	t = cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv6_route__description;
	t->description_ja("description");
	t->description_en("description");

	t = cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv6_route__next_hop;
	t->description_ja("next-hop");
	t->description_en("next-hop");

	t = cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv6_route__next_hop_multipath_entry_;
	t->description_ja("multipath-entry");
	t->description_en("multipath-entry");

	t = cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv6_route__next_hop_multipath_entry__name;
	t->description_ja("name");
	t->description_en("name");

	t = cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv6_route__next_hop_multipath_entry__outgoing_interface;
	t->description_ja("outgoing-interface");
	t->description_en("outgoing-interface");

	t = cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv6_route__next_hop_multipath_entry__next_hop_address;
	t->description_ja("next-hop-address");
	t->description_en("next-hop-address");

	t = cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv6_route__next_hop_multipath_entry__priority;
	t->description_ja("priority");
	t->description_en("priority");

	t = cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv6_route__next_hop_multipath_entry__weight;
	t->description_ja("weight");
	t->description_en("weight");

	t = cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv6_route__next_hop_outgoing_interface;
	t->description_ja("outgoing-interface");
	t->description_en("outgoing-interface");

	t = cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv6_route__next_hop_next_hop_address;
	t->description_ja("next-hop-address");
	t->description_en("next-hop-address");

	t = cmn_routing_routing_instance__router_id;
	t->description_ja("router-id");
	t->description_en("router-id");

	t = cmn_routing_ribs;
	t->description_ja("ribs");
	t->description_en("ribs");

	t = cmn_routing_ribs_rib_;
	t->description_ja("rib");
	t->description_en("rib");

	t = cmn_routing_ribs_rib__name;
	t->description_ja("name");
	t->description_en("name");

	t = cmn_routing_ribs_rib__description;
	t->description_ja("description");
	t->description_en("description");

	t = cmn_routing_ribs_rib__recipient_ribs;
	t->description_ja("recipient-ribs");
	t->description_en("recipient-ribs");

	t = cmn_routing_ribs_rib__recipient_ribs_recipient_rib_;
	t->description_ja("recipient-rib");
	t->description_en("recipient-rib");

	t = cmn_routing_ribs_rib__recipient_ribs_recipient_rib__rib_name;
	t->description_ja("rib-name");
	t->description_en("rib-name");

	t = cmn_routing_ribs_rib__recipient_ribs_recipient_rib__filter;
	t->description_ja("filter");
	t->description_en("filter");

	t = cmn_routing_ribs_rib__address_family;
	t->description_ja("address-family");
	t->description_en("address-family");

	t = cmn_routing_route_filters;
	t->description_ja("route-filters");
	t->description_en("route-filters");

	t = cmn_routing_route_filters_route_filter_;
	t->description_ja("route-filter");
	t->description_en("route-filter");

	t = cmn_routing_route_filters_route_filter__name;
	t->description_ja("name");
	t->description_en("name");

	t = cmn_routing_route_filters_route_filter__description;
	t->description_ja("description");
	t->description_en("description");

	t = cmn_routing_route_filters_route_filter__type;
	t->description_ja("type");
	t->description_en("type");
}

