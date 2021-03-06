/**
 * @file	config_model_descriptions.h
 * @brief	設定モデル説明文宣言
 * @author	Masakazu Asama <m-asama@ginzado.co.jp>
 */

#pragma once

#include "console_base.h"

extern msg cmn_interfaces_dscr[];
extern msg cmn_interfaces_interface__dscr[];
extern msg cmn_interfaces_interface__name_dscr[];
extern msg cmn_interfaces_interface__description_dscr[];
extern msg cmn_interfaces_interface__type_dscr[];
extern msg cmn_interfaces_interface__enabled_dscr[];
extern msg cmn_interfaces_interface__link_up_down_trap_enable_dscr[];
extern msg cmn_interfaces_interface__ipv4_dscr[];
extern msg cmn_interfaces_interface__ipv4_enabled_dscr[];
extern msg cmn_interfaces_interface__ipv4_forwarding_dscr[];
extern msg cmn_interfaces_interface__ipv4_mtu_dscr[];
extern msg cmn_interfaces_interface__ipv4_address__dscr[];
extern msg cmn_interfaces_interface__ipv4_address__ip_dscr[];
extern msg cmn_interfaces_interface__ipv4_address__prefix_length_dscr[];
extern msg cmn_interfaces_interface__ipv4_address__netmask_dscr[];
extern msg cmn_interfaces_interface__ipv4_neighbor__dscr[];
extern msg cmn_interfaces_interface__ipv4_neighbor__ip_dscr[];
extern msg cmn_interfaces_interface__ipv4_neighbor__link_layer_address_dscr[];
extern msg cmn_interfaces_interface__ipv6_dscr[];
extern msg cmn_interfaces_interface__ipv6_enabled_dscr[];
extern msg cmn_interfaces_interface__ipv6_forwarding_dscr[];
extern msg cmn_interfaces_interface__ipv6_mtu_dscr[];
extern msg cmn_interfaces_interface__ipv6_address__dscr[];
extern msg cmn_interfaces_interface__ipv6_address__ip_dscr[];
extern msg cmn_interfaces_interface__ipv6_address__prefix_length_dscr[];
extern msg cmn_interfaces_interface__ipv6_neighbor__dscr[];
extern msg cmn_interfaces_interface__ipv6_neighbor__ip_dscr[];
extern msg cmn_interfaces_interface__ipv6_neighbor__link_layer_address_dscr[];
extern msg cmn_interfaces_interface__ipv6_dup_addr_detect_transmits_dscr[];
extern msg cmn_interfaces_interface__ipv6_autoconf_dscr[];
extern msg cmn_interfaces_interface__ipv6_autoconf_create_global_addresses_dscr[];
extern msg cmn_interfaces_interface__ipv6_autoconf_create_temporary_addresses_dscr[];
extern msg cmn_interfaces_interface__ipv6_autoconf_temporary_valid_lifetime_dscr[];
extern msg cmn_interfaces_interface__ipv6_autoconf_temporary_preferred_lifetime_dscr[];
extern msg cmn_interfaces_state_dscr[];
extern msg cmn_interfaces_state_interface__dscr[];
extern msg cmn_interfaces_state_interface__name_dscr[];
extern msg cmn_interfaces_state_interface__type_dscr[];
extern msg cmn_interfaces_state_interface__admin_status_dscr[];
extern msg cmn_interfaces_state_interface__oper_status_dscr[];
extern msg cmn_interfaces_state_interface__last_change_dscr[];
extern msg cmn_interfaces_state_interface__if_index_dscr[];
extern msg cmn_interfaces_state_interface__phys_address_dscr[];
extern msg cmn_interfaces_state_interface__speed_dscr[];
extern msg cmn_interfaces_state_interface__statistics_dscr[];
extern msg cmn_interfaces_state_interface__statistics_discontinuity_time_dscr[];
extern msg cmn_interfaces_state_interface__statistics_in_octets_dscr[];
extern msg cmn_interfaces_state_interface__statistics_in_unicast_pkts_dscr[];
extern msg cmn_interfaces_state_interface__statistics_in_broadcast_pkts_dscr[];
extern msg cmn_interfaces_state_interface__statistics_in_multicast_pkts_dscr[];
extern msg cmn_interfaces_state_interface__statistics_in_discards_dscr[];
extern msg cmn_interfaces_state_interface__statistics_in_errors_dscr[];
extern msg cmn_interfaces_state_interface__statistics_in_unknown_protos_dscr[];
extern msg cmn_interfaces_state_interface__statistics_out_octets_dscr[];
extern msg cmn_interfaces_state_interface__statistics_out_unicast_pkts_dscr[];
extern msg cmn_interfaces_state_interface__statistics_out_broadcast_pkts_dscr[];
extern msg cmn_interfaces_state_interface__statistics_out_multicast_pkts_dscr[];
extern msg cmn_interfaces_state_interface__statistics_out_discards_dscr[];
extern msg cmn_interfaces_state_interface__statistics_out_errors_dscr[];
extern msg cmn_interfaces_state_interface__ipv4_dscr[];
extern msg cmn_interfaces_state_interface__ipv4_forwarding_dscr[];
extern msg cmn_interfaces_state_interface__ipv4_mtu_dscr[];
extern msg cmn_interfaces_state_interface__ipv4_address__dscr[];
extern msg cmn_interfaces_state_interface__ipv4_address__ip_dscr[];
extern msg cmn_interfaces_state_interface__ipv4_address__prefix_length_dscr[];
extern msg cmn_interfaces_state_interface__ipv4_address__netmask_dscr[];
extern msg cmn_interfaces_state_interface__ipv4_address__origin_dscr[];
extern msg cmn_interfaces_state_interface__ipv4_neighbor__dscr[];
extern msg cmn_interfaces_state_interface__ipv4_neighbor__ip_dscr[];
extern msg cmn_interfaces_state_interface__ipv4_neighbor__link_layer_address_dscr[];
extern msg cmn_interfaces_state_interface__ipv4_neighbor__origin_dscr[];
extern msg cmn_interfaces_state_interface__ipv6_dscr[];
extern msg cmn_interfaces_state_interface__ipv6_forwarding_dscr[];
extern msg cmn_interfaces_state_interface__ipv6_mtu_dscr[];
extern msg cmn_interfaces_state_interface__ipv6_address__dscr[];
extern msg cmn_interfaces_state_interface__ipv6_address__ip_dscr[];
extern msg cmn_interfaces_state_interface__ipv6_address__prefix_length_dscr[];
extern msg cmn_interfaces_state_interface__ipv6_address__origin_dscr[];
extern msg cmn_interfaces_state_interface__ipv6_address__status_dscr[];
extern msg cmn_interfaces_state_interface__ipv6_neighbor__dscr[];
extern msg cmn_interfaces_state_interface__ipv6_neighbor__ip_dscr[];
extern msg cmn_interfaces_state_interface__ipv6_neighbor__link_layer_address_dscr[];
extern msg cmn_interfaces_state_interface__ipv6_neighbor__origin_dscr[];
extern msg cmn_interfaces_state_interface__ipv6_neighbor__is_router_dscr[];
extern msg cmn_interfaces_state_interface__ipv6_neighbor__state_dscr[];
extern msg cmn_routing_state_dscr[];
extern msg cmn_routing_state_routing_instance__dscr[];
extern msg cmn_routing_state_routing_instance__name_dscr[];
extern msg cmn_routing_state_routing_instance__type_dscr[];
extern msg cmn_routing_state_routing_instance__default_ribs_dscr[];
extern msg cmn_routing_state_routing_instance__default_ribs_default_rib__dscr[];
extern msg cmn_routing_state_routing_instance__default_ribs_default_rib__rib_name_dscr[];
extern msg cmn_routing_state_routing_instance__default_ribs_default_rib__address_family_dscr[];
extern msg cmn_routing_state_routing_instance__interfaces_dscr[];
extern msg cmn_routing_state_routing_instance__interfaces_interface__dscr[];
extern msg cmn_routing_state_routing_instance__interfaces_interface__name_dscr[];
extern msg cmn_routing_state_routing_instance__interfaces_interface__ipv6_router_advertisements_dscr[];
extern msg cmn_routing_state_routing_instance__interfaces_interface__ipv6_router_advertisements_send_advertisements_dscr[];
extern msg cmn_routing_state_routing_instance__interfaces_interface__ipv6_router_advertisements_max_rtr_adv_interval_dscr[];
extern msg cmn_routing_state_routing_instance__interfaces_interface__ipv6_router_advertisements_min_rtr_adv_interval_dscr[];
extern msg cmn_routing_state_routing_instance__interfaces_interface__ipv6_router_advertisements_managed_flag_dscr[];
extern msg cmn_routing_state_routing_instance__interfaces_interface__ipv6_router_advertisements_other_config_flag_dscr[];
extern msg cmn_routing_state_routing_instance__interfaces_interface__ipv6_router_advertisements_link_mtu_dscr[];
extern msg cmn_routing_state_routing_instance__interfaces_interface__ipv6_router_advertisements_reachable_time_dscr[];
extern msg cmn_routing_state_routing_instance__interfaces_interface__ipv6_router_advertisements_retrans_timer_dscr[];
extern msg cmn_routing_state_routing_instance__interfaces_interface__ipv6_router_advertisements_cur_hop_limit_dscr[];
extern msg cmn_routing_state_routing_instance__interfaces_interface__ipv6_router_advertisements_default_lifetime_dscr[];
extern msg cmn_routing_state_routing_instance__interfaces_interface__ipv6_router_advertisements_prefix_list_dscr[];
extern msg cmn_routing_state_routing_instance__interfaces_interface__ipv6_router_advertisements_prefix_list_prefix__dscr[];
extern msg cmn_routing_state_routing_instance__interfaces_interface__ipv6_router_advertisements_prefix_list_prefix__prefix_spec_dscr[];
extern msg cmn_routing_state_routing_instance__interfaces_interface__ipv6_router_advertisements_prefix_list_prefix__valid_lifetime_dscr[];
extern msg cmn_routing_state_routing_instance__interfaces_interface__ipv6_router_advertisements_prefix_list_prefix__on_link_flag_dscr[];
extern msg cmn_routing_state_routing_instance__interfaces_interface__ipv6_router_advertisements_prefix_list_prefix__preferred_lifetime_dscr[];
extern msg cmn_routing_state_routing_instance__interfaces_interface__ipv6_router_advertisements_prefix_list_prefix__autonomous_flag_dscr[];
extern msg cmn_routing_state_routing_instance__routing_protocols_dscr[];
extern msg cmn_routing_state_routing_instance__routing_protocols_routing_protocol__dscr[];
extern msg cmn_routing_state_routing_instance__routing_protocols_routing_protocol__type_dscr[];
extern msg cmn_routing_state_routing_instance__routing_protocols_routing_protocol__name_dscr[];
extern msg cmn_routing_state_routing_instance__routing_protocols_routing_protocol__route_preference_dscr[];
extern msg cmn_routing_state_routing_instance__routing_protocols_routing_protocol__connected_ribs_dscr[];
extern msg cmn_routing_state_routing_instance__routing_protocols_routing_protocol__connected_ribs_connected_rib__dscr[];
extern msg cmn_routing_state_routing_instance__routing_protocols_routing_protocol__connected_ribs_connected_rib__rib_name_dscr[];
extern msg cmn_routing_state_routing_instance__routing_protocols_routing_protocol__connected_ribs_connected_rib__import_filter_dscr[];
extern msg cmn_routing_state_routing_instance__routing_protocols_routing_protocol__connected_ribs_connected_rib__export_filter_dscr[];
extern msg cmn_routing_state_routing_instance__id_dscr[];
extern msg cmn_routing_state_next_hop_lists_dscr[];
extern msg cmn_routing_state_next_hop_lists_next_hop_list__dscr[];
extern msg cmn_routing_state_next_hop_lists_next_hop_list__next_hop__dscr[];
extern msg cmn_routing_state_next_hop_lists_next_hop_list__next_hop__next_hop_list_dscr[];
extern msg cmn_routing_state_next_hop_lists_next_hop_list__next_hop__use_rib_dscr[];
extern msg cmn_routing_state_next_hop_lists_next_hop_list__next_hop__outgoing_interface_dscr[];
extern msg cmn_routing_state_next_hop_lists_next_hop_list__next_hop__next_hop_address_dscr[];
extern msg cmn_routing_state_next_hop_lists_next_hop_list__next_hop__special_next_hop_dscr[];
extern msg cmn_routing_state_next_hop_lists_next_hop_list__next_hop__priority_dscr[];
extern msg cmn_routing_state_next_hop_lists_next_hop_list__next_hop__weight_dscr[];
extern msg cmn_routing_state_next_hop_lists_next_hop_list__id_dscr[];
extern msg cmn_routing_state_next_hop_lists_next_hop_list__address_family_dscr[];
extern msg cmn_routing_state_ribs_dscr[];
extern msg cmn_routing_state_ribs_rib__dscr[];
extern msg cmn_routing_state_ribs_rib__name_dscr[];
extern msg cmn_routing_state_ribs_rib__routes_dscr[];
extern msg cmn_routing_state_ribs_rib__routes_route__dscr[];
extern msg cmn_routing_state_ribs_rib__routes_route__route_preference_dscr[];
extern msg cmn_routing_state_ribs_rib__routes_route__next_hop_dscr[];
extern msg cmn_routing_state_ribs_rib__routes_route__next_hop_next_hop_list_dscr[];
extern msg cmn_routing_state_ribs_rib__routes_route__next_hop_use_rib_dscr[];
extern msg cmn_routing_state_ribs_rib__routes_route__next_hop_outgoing_interface_dscr[];
extern msg cmn_routing_state_ribs_rib__routes_route__next_hop_next_hop_address_dscr[];
extern msg cmn_routing_state_ribs_rib__routes_route__next_hop_next_hop_dscr[];
extern msg cmn_routing_state_ribs_rib__routes_route__next_hop_special_next_hop_dscr[];
extern msg cmn_routing_state_ribs_rib__routes_route__source_protocol_dscr[];
extern msg cmn_routing_state_ribs_rib__routes_route__active_dscr[];
extern msg cmn_routing_state_ribs_rib__routes_route__last_updated_dscr[];
extern msg cmn_routing_state_ribs_rib__routes_route__destination_prefix_dscr[];
extern msg cmn_routing_state_ribs_rib__recipient_ribs_dscr[];
extern msg cmn_routing_state_ribs_rib__recipient_ribs_recipient_rib__dscr[];
extern msg cmn_routing_state_ribs_rib__recipient_ribs_recipient_rib__rib_name_dscr[];
extern msg cmn_routing_state_ribs_rib__recipient_ribs_recipient_rib__filter_dscr[];
extern msg cmn_routing_state_ribs_rib__id_dscr[];
extern msg cmn_routing_state_ribs_rib__address_family_dscr[];
extern msg cmn_routing_state_route_filters_dscr[];
extern msg cmn_routing_state_route_filters_route_filter__dscr[];
extern msg cmn_routing_state_route_filters_route_filter__name_dscr[];
extern msg cmn_routing_state_route_filters_route_filter__type_dscr[];
extern msg cmn_routing_dscr[];
extern msg cmn_routing_routing_instance__dscr[];
extern msg cmn_routing_routing_instance__name_dscr[];
extern msg cmn_routing_routing_instance__type_dscr[];
extern msg cmn_routing_routing_instance__enabled_dscr[];
extern msg cmn_routing_routing_instance__description_dscr[];
extern msg cmn_routing_routing_instance__default_ribs_dscr[];
extern msg cmn_routing_routing_instance__default_ribs_default_rib__dscr[];
extern msg cmn_routing_routing_instance__default_ribs_default_rib__rib_name_dscr[];
extern msg cmn_routing_routing_instance__default_ribs_default_rib__address_family_dscr[];
extern msg cmn_routing_routing_instance__interfaces_dscr[];
extern msg cmn_routing_routing_instance__interfaces_interface__dscr[];
extern msg cmn_routing_routing_instance__interfaces_interface__name_dscr[];
extern msg cmn_routing_routing_instance__interfaces_interface__ipv6_router_advertisements_dscr[];
extern msg cmn_routing_routing_instance__interfaces_interface__ipv6_router_advertisements_send_advertisements_dscr[];
extern msg cmn_routing_routing_instance__interfaces_interface__ipv6_router_advertisements_max_rtr_adv_interval_dscr[];
extern msg cmn_routing_routing_instance__interfaces_interface__ipv6_router_advertisements_min_rtr_adv_interval_dscr[];
extern msg cmn_routing_routing_instance__interfaces_interface__ipv6_router_advertisements_managed_flag_dscr[];
extern msg cmn_routing_routing_instance__interfaces_interface__ipv6_router_advertisements_other_config_flag_dscr[];
extern msg cmn_routing_routing_instance__interfaces_interface__ipv6_router_advertisements_link_mtu_dscr[];
extern msg cmn_routing_routing_instance__interfaces_interface__ipv6_router_advertisements_reachable_time_dscr[];
extern msg cmn_routing_routing_instance__interfaces_interface__ipv6_router_advertisements_retrans_timer_dscr[];
extern msg cmn_routing_routing_instance__interfaces_interface__ipv6_router_advertisements_cur_hop_limit_dscr[];
extern msg cmn_routing_routing_instance__interfaces_interface__ipv6_router_advertisements_default_lifetime_dscr[];
extern msg cmn_routing_routing_instance__interfaces_interface__ipv6_router_advertisements_prefix_list_dscr[];
extern msg cmn_routing_routing_instance__interfaces_interface__ipv6_router_advertisements_prefix_list_prefix__dscr[];
extern msg cmn_routing_routing_instance__interfaces_interface__ipv6_router_advertisements_prefix_list_prefix__prefix_spec_dscr[];
extern msg cmn_routing_routing_instance__interfaces_interface__ipv6_router_advertisements_prefix_list_prefix__no_advertise_dscr[];
extern msg cmn_routing_routing_instance__interfaces_interface__ipv6_router_advertisements_prefix_list_prefix__valid_lifetime_dscr[];
extern msg cmn_routing_routing_instance__interfaces_interface__ipv6_router_advertisements_prefix_list_prefix__on_link_flag_dscr[];
extern msg cmn_routing_routing_instance__interfaces_interface__ipv6_router_advertisements_prefix_list_prefix__preferred_lifetime_dscr[];
extern msg cmn_routing_routing_instance__interfaces_interface__ipv6_router_advertisements_prefix_list_prefix__autonomous_flag_dscr[];
extern msg cmn_routing_routing_instance__routing_protocols_dscr[];
extern msg cmn_routing_routing_instance__routing_protocols_routing_protocol__dscr[];
extern msg cmn_routing_routing_instance__routing_protocols_routing_protocol__type_dscr[];
extern msg cmn_routing_routing_instance__routing_protocols_routing_protocol__name_dscr[];
extern msg cmn_routing_routing_instance__routing_protocols_routing_protocol__description_dscr[];
extern msg cmn_routing_routing_instance__routing_protocols_routing_protocol__enabled_dscr[];
extern msg cmn_routing_routing_instance__routing_protocols_routing_protocol__route_preference_dscr[];
extern msg cmn_routing_routing_instance__routing_protocols_routing_protocol__connected_ribs_dscr[];
extern msg cmn_routing_routing_instance__routing_protocols_routing_protocol__connected_ribs_connected_rib__dscr[];
extern msg cmn_routing_routing_instance__routing_protocols_routing_protocol__connected_ribs_connected_rib__rib_name_dscr[];
extern msg cmn_routing_routing_instance__routing_protocols_routing_protocol__connected_ribs_connected_rib__import_filter_dscr[];
extern msg cmn_routing_routing_instance__routing_protocols_routing_protocol__connected_ribs_connected_rib__export_filter_dscr[];
extern msg cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_dscr[];
extern msg cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv4_dscr[];
extern msg cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv4_route__dscr[];
extern msg cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv4_route__destination_prefix_dscr[];
extern msg cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv4_route__description_dscr[];
extern msg cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv4_route__next_hop_dscr[];
extern msg cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv4_route__next_hop_multipath_entry__dscr[];
extern msg cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv4_route__next_hop_multipath_entry__name_dscr[];
extern msg cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv4_route__next_hop_multipath_entry__outgoing_interface_dscr[];
extern msg cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv4_route__next_hop_multipath_entry__next_hop_address_dscr[];
extern msg cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv4_route__next_hop_multipath_entry__priority_dscr[];
extern msg cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv4_route__next_hop_multipath_entry__weight_dscr[];
extern msg cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv4_route__next_hop_outgoing_interface_dscr[];
extern msg cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv4_route__next_hop_next_hop_address_dscr[];
extern msg cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv6_dscr[];
extern msg cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv6_route__dscr[];
extern msg cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv6_route__destination_prefix_dscr[];
extern msg cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv6_route__description_dscr[];
extern msg cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv6_route__next_hop_dscr[];
extern msg cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv6_route__next_hop_multipath_entry__dscr[];
extern msg cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv6_route__next_hop_multipath_entry__name_dscr[];
extern msg cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv6_route__next_hop_multipath_entry__outgoing_interface_dscr[];
extern msg cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv6_route__next_hop_multipath_entry__next_hop_address_dscr[];
extern msg cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv6_route__next_hop_multipath_entry__priority_dscr[];
extern msg cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv6_route__next_hop_multipath_entry__weight_dscr[];
extern msg cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv6_route__next_hop_outgoing_interface_dscr[];
extern msg cmn_routing_routing_instance__routing_protocols_routing_protocol__static_routes_ipv6_route__next_hop_next_hop_address_dscr[];
extern msg cmn_routing_routing_instance__router_id_dscr[];
extern msg cmn_routing_ribs_dscr[];
extern msg cmn_routing_ribs_rib__dscr[];
extern msg cmn_routing_ribs_rib__name_dscr[];
extern msg cmn_routing_ribs_rib__description_dscr[];
extern msg cmn_routing_ribs_rib__recipient_ribs_dscr[];
extern msg cmn_routing_ribs_rib__recipient_ribs_recipient_rib__dscr[];
extern msg cmn_routing_ribs_rib__recipient_ribs_recipient_rib__rib_name_dscr[];
extern msg cmn_routing_ribs_rib__recipient_ribs_recipient_rib__filter_dscr[];
extern msg cmn_routing_ribs_rib__address_family_dscr[];
extern msg cmn_routing_route_filters_dscr[];
extern msg cmn_routing_route_filters_route_filter__dscr[];
extern msg cmn_routing_route_filters_route_filter__name_dscr[];
extern msg cmn_routing_route_filters_route_filter__description_dscr[];
extern msg cmn_routing_route_filters_route_filter__type_dscr[];

