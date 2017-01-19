/**
 * @file	config_model_nodes.cpp
 * @brief	設定モデルノード実装
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#include "config_model_node.h"

config_model_node *cmn_interfaces;
config_model_node *cmn_interfaces_interface_;
config_model_node *cmn_interfaces_interface__name;
config_model_node *cmn_interfaces_interface__description;
config_model_node *cmn_interfaces_interface__type;
config_model_node *cmn_interfaces_interface__enabled;
config_model_node *cmn_interfaces_interface__link_up_down_trap_enable;
config_model_node *cmn_interfaces_interface__ipv4;
config_model_node *cmn_interfaces_interface__ipv4_enabled;
config_model_node *cmn_interfaces_interface__ipv4_forwarding;
config_model_node *cmn_interfaces_interface__ipv4_mtu;
config_model_node *cmn_interfaces_interface__ipv4_address_;
config_model_node *cmn_interfaces_interface__ipv4_address__ip;
config_model_node *cmn_interfaces_interface__ipv4_address__prefix_length;
config_model_node *cmn_interfaces_interface__ipv4_address__netmask;
config_model_node *cmn_interfaces_interface__ipv4_neighbor_;
config_model_node *cmn_interfaces_interface__ipv4_neighbor__ip;
config_model_node *cmn_interfaces_interface__ipv4_neighbor__link_layer_address;
config_model_node *cmn_interfaces_interface__ipv6;
config_model_node *cmn_interfaces_interface__ipv6_enabled;
config_model_node *cmn_interfaces_interface__ipv6_forwarding;
config_model_node *cmn_interfaces_interface__ipv6_mtu;
config_model_node *cmn_interfaces_interface__ipv6_address_;
config_model_node *cmn_interfaces_interface__ipv6_address__ip;
config_model_node *cmn_interfaces_interface__ipv6_address__prefix_length;
config_model_node *cmn_interfaces_interface__ipv6_neighbor_;
config_model_node *cmn_interfaces_interface__ipv6_neighbor__ip;
config_model_node *cmn_interfaces_interface__ipv6_neighbor__link_layer_address;
config_model_node *cmn_interfaces_interface__ipv6_dup_addr_detect_transmits;
config_model_node *cmn_interfaces_interface__ipv6_autoconf;
config_model_node *cmn_interfaces_interface__ipv6_autoconf_create_global_addresses;
config_model_node *cmn_interfaces_interface__ipv6_autoconf_create_temporary_addresses;
config_model_node *cmn_interfaces_interface__ipv6_autoconf_temporary_valid_lifetime;
config_model_node *cmn_interfaces_interface__ipv6_autoconf_temporary_preferred_lifetime;
config_model_node *cmn_interfaces_state;
config_model_node *cmn_interfaces_state_interface_;
config_model_node *cmn_interfaces_state_interface__name;
config_model_node *cmn_interfaces_state_interface__type;
config_model_node *cmn_interfaces_state_interface__admin_status;
config_model_node *cmn_interfaces_state_interface__oper_status;
config_model_node *cmn_interfaces_state_interface__last_change;
config_model_node *cmn_interfaces_state_interface__if_index;
config_model_node *cmn_interfaces_state_interface__phys_address;
config_model_node *cmn_interfaces_state_interface__speed;
config_model_node *cmn_interfaces_state_interface__statistics;
config_model_node *cmn_interfaces_state_interface__statistics_discontinuity_time;
config_model_node *cmn_interfaces_state_interface__statistics_in_octets;
config_model_node *cmn_interfaces_state_interface__statistics_in_unicast_pkts;
config_model_node *cmn_interfaces_state_interface__statistics_in_broadcast_pkts;
config_model_node *cmn_interfaces_state_interface__statistics_in_multicast_pkts;
config_model_node *cmn_interfaces_state_interface__statistics_in_discards;
config_model_node *cmn_interfaces_state_interface__statistics_in_errors;
config_model_node *cmn_interfaces_state_interface__statistics_in_unknown_protos;
config_model_node *cmn_interfaces_state_interface__statistics_out_octets;
config_model_node *cmn_interfaces_state_interface__statistics_out_unicast_pkts;
config_model_node *cmn_interfaces_state_interface__statistics_out_broadcast_pkts;
config_model_node *cmn_interfaces_state_interface__statistics_out_multicast_pkts;
config_model_node *cmn_interfaces_state_interface__statistics_out_discards;
config_model_node *cmn_interfaces_state_interface__statistics_out_errors;
config_model_node *cmn_interfaces_state_interface__ipv4;
config_model_node *cmn_interfaces_state_interface__ipv4_forwarding;
config_model_node *cmn_interfaces_state_interface__ipv4_mtu;
config_model_node *cmn_interfaces_state_interface__ipv4_address_;
config_model_node *cmn_interfaces_state_interface__ipv4_address__ip;
config_model_node *cmn_interfaces_state_interface__ipv4_address__prefix_length;
config_model_node *cmn_interfaces_state_interface__ipv4_address__netmask;
config_model_node *cmn_interfaces_state_interface__ipv4_address__origin;
config_model_node *cmn_interfaces_state_interface__ipv4_neighbor_;
config_model_node *cmn_interfaces_state_interface__ipv4_neighbor__ip;
config_model_node *cmn_interfaces_state_interface__ipv4_neighbor__link_layer_address;
config_model_node *cmn_interfaces_state_interface__ipv4_neighbor__origin;
config_model_node *cmn_interfaces_state_interface__ipv6;
config_model_node *cmn_interfaces_state_interface__ipv6_forwarding;
config_model_node *cmn_interfaces_state_interface__ipv6_mtu;
config_model_node *cmn_interfaces_state_interface__ipv6_address_;
config_model_node *cmn_interfaces_state_interface__ipv6_address__ip;
config_model_node *cmn_interfaces_state_interface__ipv6_address__prefix_length;
config_model_node *cmn_interfaces_state_interface__ipv6_address__origin;
config_model_node *cmn_interfaces_state_interface__ipv6_address__status;
config_model_node *cmn_interfaces_state_interface__ipv6_neighbor_;
config_model_node *cmn_interfaces_state_interface__ipv6_neighbor__ip;
config_model_node *cmn_interfaces_state_interface__ipv6_neighbor__link_layer_address;
config_model_node *cmn_interfaces_state_interface__ipv6_neighbor__origin;
config_model_node *cmn_interfaces_state_interface__ipv6_neighbor__is_router;
config_model_node *cmn_interfaces_state_interface__ipv6_neighbor__state;
config_model_node *cmn_routing_state;
config_model_node *cmn_routing_state_routing_instance_;
config_model_node *cmn_routing_state_routing_instance__name;
config_model_node *cmn_routing_state_routing_instance__type;
config_model_node *cmn_routing_state_routing_instance__default_ribs;
config_model_node *cmn_routing_state_routing_instance__default_ribs_default_rib_;
config_model_node *cmn_routing_state_routing_instance__default_ribs_default_rib__rib_name;
config_model_node *cmn_routing_state_routing_instance__default_ribs_default_rib__address_family;
config_model_node *cmn_routing_state_routing_instance__interfaces;
config_model_node *cmn_routing_state_routing_instance__interfaces_interface_;
config_model_node *cmn_routing_state_routing_instance__interfaces_interface__name;
config_model_node *cmn_routing_state_routing_instance__interfaces_interface__ipv6_router_advertisements;
config_model_node *cmn_routing_state_routing_instance__interfaces_interface__ipv6_router_advertisements_send_advertisements;
config_model_node *cmn_routing_state_routing_instance__interfaces_interface__ipv6_router_advertisements_max_rtr_adv_interval;
config_model_node *cmn_routing_state_routing_instance__interfaces_interface__ipv6_router_advertisements_min_rtr_adv_interval;
config_model_node *cmn_routing_state_routing_instance__interfaces_interface__ipv6_router_advertisements_managed_flag;
config_model_node *cmn_routing_state_routing_instance__interfaces_interface__ipv6_router_advertisements_other_config_flag;
config_model_node *cmn_routing_state_routing_instance__interfaces_interface__ipv6_router_advertisements_link_mtu;
config_model_node *cmn_routing_state_routing_instance__interfaces_interface__ipv6_router_advertisements_reachable_time;
config_model_node *cmn_routing_state_routing_instance__interfaces_interface__ipv6_router_advertisements_retrans_timer;
config_model_node *cmn_routing_state_routing_instance__interfaces_interface__ipv6_router_advertisements_cur_hop_limit;
config_model_node *cmn_routing_state_routing_instance__interfaces_interface__ipv6_router_advertisements_default_lifetime;
config_model_node *cmn_routing_state_routing_instance__interfaces_interface__ipv6_router_advertisements_prefix_list;
config_model_node *cmn_routing_state_routing_instance__interfaces_interface__ipv6_router_advertisements_prefix_list_prefix_;
config_model_node *cmn_routing_state_routing_instance__interfaces_interface__ipv6_router_advertisements_prefix_list_prefix__prefix_spec;
config_model_node *cmn_routing_state_routing_instance__interfaces_interface__ipv6_router_advertisements_prefix_list_prefix__valid_lifetime;
config_model_node *cmn_routing_state_routing_instance__interfaces_interface__ipv6_router_advertisements_prefix_list_prefix__on_link_flag;
config_model_node *cmn_routing_state_routing_instance__interfaces_interface__ipv6_router_advertisements_prefix_list_prefix__preferred_lifetime;
config_model_node *cmn_routing_state_routing_instance__interfaces_interface__ipv6_router_advertisements_prefix_list_prefix__autonomous_flag;
config_model_node *cmn_routing_state_routing_instance__routing_protocols;
config_model_node *cmn_routing_state_routing_instance__routing_protocols_routing_protocol_;
config_model_node *cmn_routing_state_routing_instance__routing_protocols_routing_protocol__type;
config_model_node *cmn_routing_state_routing_instance__routing_protocols_routing_protocol__name;
config_model_node *cmn_routing_state_routing_instance__routing_protocols_routing_protocol__route_preference;
config_model_node *cmn_routing_state_routing_instance__routing_protocols_routing_protocol__connected_ribs;
config_model_node *cmn_routing_state_routing_instance__routing_protocols_routing_protocol__connected_ribs_connected_rib_;
config_model_node *cmn_routing_state_routing_instance__routing_protocols_routing_protocol__connected_ribs_connected_rib__rib_name;
config_model_node *cmn_routing_state_routing_instance__routing_protocols_routing_protocol__connected_ribs_connected_rib__import_filter;
config_model_node *cmn_routing_state_routing_instance__routing_protocols_routing_protocol__connected_ribs_connected_rib__export_filter;
config_model_node *cmn_routing_state_routing_instance__id;
config_model_node *cmn_routing_state_next_hop_lists;
config_model_node *cmn_routing_state_next_hop_lists_next_hop_list_;
config_model_node *cmn_routing_state_next_hop_lists_next_hop_list__next_hop_;
config_model_node *cmn_routing_state_next_hop_lists_next_hop_list__next_hop__next_hop_list;
config_model_node *cmn_routing_state_next_hop_lists_next_hop_list__next_hop__use_rib;
config_model_node *cmn_routing_state_next_hop_lists_next_hop_list__next_hop__outgoing_interface;
config_model_node *cmn_routing_state_next_hop_lists_next_hop_list__next_hop__next_hop_address;
//config_model_node *cmn_routing_state_next_hop_lists_next_hop_list__next_hop__next_hop_address;
config_model_node *cmn_routing_state_next_hop_lists_next_hop_list__next_hop__special_next_hop;
config_model_node *cmn_routing_state_next_hop_lists_next_hop_list__next_hop__priority;
config_model_node *cmn_routing_state_next_hop_lists_next_hop_list__next_hop__weight;
config_model_node *cmn_routing_state_next_hop_lists_next_hop_list__id;
config_model_node *cmn_routing_state_next_hop_lists_next_hop_list__address_family;
config_model_node *cmn_routing_state_ribs;
config_model_node *cmn_routing_state_ribs_rib_;
config_model_node *cmn_routing_state_ribs_rib__name;
config_model_node *cmn_routing_state_ribs_rib__routes;
config_model_node *cmn_routing_state_ribs_rib__routes_route_;
config_model_node *cmn_routing_state_ribs_rib__routes_route__route_preference;
config_model_node *cmn_routing_state_ribs_rib__routes_route__next_hop;
config_model_node *cmn_routing_state_ribs_rib__routes_route__next_hop_next_hop_list;
config_model_node *cmn_routing_state_ribs_rib__routes_route__next_hop_use_rib;
config_model_node *cmn_routing_state_ribs_rib__routes_route__next_hop_outgoing_interface;
config_model_node *cmn_routing_state_ribs_rib__routes_route__next_hop_next_hop_address;
config_model_node *cmn_routing_state_ribs_rib__routes_route__next_hop_next_hop;
config_model_node *cmn_routing_state_ribs_rib__routes_route__next_hop_special_next_hop;
config_model_node *cmn_routing_state_ribs_rib__routes_route__source_protocol;
config_model_node *cmn_routing_state_ribs_rib__routes_route__active;
config_model_node *cmn_routing_state_ribs_rib__routes_route__last_updated;
config_model_node *cmn_routing_state_ribs_rib__routes_route__destination_prefix;
//config_model_node *cmn_routing_state_ribs_rib__routes_route__destination_prefix;
config_model_node *cmn_routing_state_ribs_rib__recipient_ribs;
config_model_node *cmn_routing_state_ribs_rib__recipient_ribs_recipient_rib_;
config_model_node *cmn_routing_state_ribs_rib__recipient_ribs_recipient_rib__rib_name;
config_model_node *cmn_routing_state_ribs_rib__recipient_ribs_recipient_rib__filter;
config_model_node *cmn_routing_state_ribs_rib__id;
config_model_node *cmn_routing_state_ribs_rib__address_family;
config_model_node *cmn_routing_state_route_filters;
config_model_node *cmn_routing_state_route_filters_route_filter_;
config_model_node *cmn_routing_state_route_filters_route_filter__name;
config_model_node *cmn_routing_state_route_filters_route_filter__type;
config_model_node *cmn_routing;
config_model_node *cmn_routing_routing_instance_;
config_model_node *cmn_routing_routing_instance__name;
config_model_node *cmn_routing_routing_instance__type;
config_model_node *cmn_routing_routing_instance__enabled;
config_model_node *cmn_routing_routing_instance__description;
config_model_node *cmn_routing_routing_instance__default_ribs;
config_model_node *cmn_routing_routing_instance__default_ribs_default_rib_;
config_model_node *cmn_routing_routing_instance__default_ribs_default_rib__rib_name;
config_model_node *cmn_routing_routing_instance__default_ribs_default_rib__address_family;
config_model_node *cmn_routing_routing_instance__interfaces;
config_model_node *cmn_routing_routing_instance__interfaces_interface_;
config_model_node *cmn_routing_routing_instance__interfaces_interface__name;
config_model_node *cmn_routing_routing_instance__interfaces_interface__ipv6_router_advertisements;
config_model_node *cmn_routing_routing_instance__interfaces_interface__ipv6_router_advertisements_send_advertisements;
config_model_node *cmn_routing_routing_instance__interfaces_interface__ipv6_router_advertisements_max_rtr_adv_interval;
config_model_node *cmn_routing_routing_instance__interfaces_interface__ipv6_router_advertisements_min_rtr_adv_interval;
config_model_node *cmn_routing_routing_instance__interfaces_interface__ipv6_router_advertisements_managed_flag;
config_model_node *cmn_routing_routing_instance__interfaces_interface__ipv6_router_advertisements_other_config_flag;
config_model_node *cmn_routing_routing_instance__interfaces_interface__ipv6_router_advertisements_link_mtu;
config_model_node *cmn_routing_routing_instance__interfaces_interface__ipv6_router_advertisements_reachable_time;
config_model_node *cmn_routing_routing_instance__interfaces_interface__ipv6_router_advertisements_retrans_timer;
config_model_node *cmn_routing_routing_instance__interfaces_interface__ipv6_router_advertisements_cur_hop_limit;
config_model_node *cmn_routing_routing_instance__interfaces_interface__ipv6_router_advertisements_default_lifetime;
config_model_node *cmn_routing_routing_instance__interfaces_interface__ipv6_router_advertisements_prefix_list;
config_model_node *cmn_routing_routing_instance__interfaces_interface__ipv6_router_advertisements_prefix_list_prefix_;
config_model_node *cmn_routing_routing_instance__interfaces_interface__ipv6_router_advertisements_prefix_list_prefix__prefix_spec;
config_model_node *cmn_routing_routing_instance__interfaces_interface__ipv6_router_advertisements_prefix_list_prefix__no_advertise;
config_model_node *cmn_routing_routing_instance__interfaces_interface__ipv6_router_advertisements_prefix_list_prefix__valid_lifetime;
config_model_node *cmn_routing_routing_instance__interfaces_interface__ipv6_router_advertisements_prefix_list_prefix__on_link_flag;
config_model_node *cmn_routing_routing_instance__interfaces_interface__ipv6_router_advertisements_prefix_list_prefix__preferred_lifetime;
config_model_node *cmn_routing_routing_instance__interfaces_interface__ipv6_router_advertisements_prefix_list_prefix__autonomous_flag;
config_model_node *cmn_routing_routing_instance__routing_protocols;
config_model_node *cmn_routing_routing_instance__routing_protocols_routing_protocol_;
config_model_node *cmn_routing_routing_instance__routing_protocols_routing_protocol__type;
config_model_node *cmn_routing_routing_instance__routing_protocols_routing_protocol__name;
config_model_node *cmn_routing_routing_instance__routing_protocols_routing_protocol__description;
config_model_node *cmn_routing_routing_instance__routing_protocols_routing_protocol__enabled;
config_model_node *cmn_routing_routing_instance__routing_protocols_routing_protocol__route_preference;
config_model_node *cmn_routing_routing_instance__routing_protocols_routing_protocol__connected_ribs;
config_model_node *cmn_routing_routing_instance__routing_protocols_routing_protocol__connected_ribs_connected_rib_;
config_model_node *cmn_routing_routing_instance__routing_protocols_routing_protocol__connected_ribs_connected_rib__rib_name;
config_model_node *cmn_routing_routing_instance__routing_protocols_routing_protocol__connected_ribs_connected_rib__import_filter;
config_model_node *cmn_routing_routing_instance__routing_protocols_routing_protocol__connected_ribs_connected_rib__export_filter;
config_model_node *cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes;
config_model_node *cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv4;
config_model_node *cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv4_route_;
config_model_node *cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv4_route__destination_prefix;
config_model_node *cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv4_route__description;
config_model_node *cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv4_route__next_hop;
config_model_node *cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv4_route__next_hop_multipath_entry_;
config_model_node *cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv4_route__next_hop_multipath_entry__name;
config_model_node *cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv4_route__next_hop_multipath_entry__outgoing_interface;
config_model_node *cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv4_route__next_hop_multipath_entry__next_hop_address;
config_model_node *cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv4_route__next_hop_multipath_entry__priority;
config_model_node *cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv4_route__next_hop_multipath_entry__weight;
config_model_node *cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv4_route__next_hop_outgoing_interface;
config_model_node *cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv4_route__next_hop_next_hop_address;
config_model_node *cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv6;
config_model_node *cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv6_route_;
config_model_node *cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv6_route__destination_prefix;
config_model_node *cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv6_route__description;
config_model_node *cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv6_route__next_hop;
config_model_node *cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv6_route__next_hop_multipath_entry_;
config_model_node *cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv6_route__next_hop_multipath_entry__name;
config_model_node *cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv6_route__next_hop_multipath_entry__outgoing_interface;
config_model_node *cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv6_route__next_hop_multipath_entry__next_hop_address;
config_model_node *cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv6_route__next_hop_multipath_entry__priority;
config_model_node *cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv6_route__next_hop_multipath_entry__weight;
config_model_node *cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv6_route__next_hop_outgoing_interface;
config_model_node *cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv6_route__next_hop_next_hop_address;
config_model_node *cmn_routing_routing_instance__router_id;
config_model_node *cmn_routing_ribs;
config_model_node *cmn_routing_ribs_rib_;
config_model_node *cmn_routing_ribs_rib__name;
config_model_node *cmn_routing_ribs_rib__description;
config_model_node *cmn_routing_ribs_rib__recipient_ribs;
config_model_node *cmn_routing_ribs_rib__recipient_ribs_recipient_rib_;
config_model_node *cmn_routing_ribs_rib__recipient_ribs_recipient_rib__rib_name;
config_model_node *cmn_routing_ribs_rib__recipient_ribs_recipient_rib__filter;
config_model_node *cmn_routing_ribs_rib__address_family;
config_model_node *cmn_routing_route_filters;
config_model_node *cmn_routing_route_filters_route_filter_;
config_model_node *cmn_routing_route_filters_route_filter__name;
config_model_node *cmn_routing_route_filters_route_filter__description;
config_model_node *cmn_routing_route_filters_route_filter__type;
