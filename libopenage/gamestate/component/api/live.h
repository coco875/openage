// Copyright 2021-2023 the openage authors. See copying.md for legal info.

#pragma once

#include <nyan/nyan.h>

#include "curve/map.h"
#include "curve/segmented.h"
#include "gamestate/component/api_component.h"

namespace openage::gamestate::component {
class Live : public APIComponent {
public:
	using APIComponent::APIComponent;

	component_t get_type() const override;

	/**
     * Add a new attribute to the component attributes.
     *
     * @param time The time at which the attribute is added.
     * @param attribute Attribute identifier (fqon of the nyan object).
     * @param starting_values Attribute values at the time of addition.
     */
	void add_attribute(const curve::time_t &time,
	                   const nyan::fqon_t &attribute,
	                   std::shared_ptr<curve::Discrete<int64_t>> starting_values);

	/**
     * Set the value of an attribute at a given time.
     *
     * @param time The time at which the attribute is set.
     * @param attribute Attribute identifier (fqon of the nyan object).
     * @param value New attribute value.
     */
	void set_attribute(const curve::time_t &time,
	                   const nyan::fqon_t &attribute,
	                   int64_t value);

private:
	using attribute_storage_t = curve::UnorderedMap<nyan::fqon_t,
	                                                std::shared_ptr<curve::Discrete<int64_t>>>;

	/**
	 * Map of attribute values by attribute type.
	 */
	attribute_storage_t attribute_values;
};

} // namespace openage::gamestate::component
