// Copyright (C) 2018-2021 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

///////////////////////////////////////////////////////////////////////////////////////////////////
#pragma once
#include "api/crop.hpp"
#include "primitive_inst.h"
#include <string>
#include <memory>

namespace cldnn {

template <>
struct typed_program_node<crop> : public typed_program_node_base<crop> {
private:
    using parent = typed_program_node_base<crop>;

public:
    using parent::parent;

    typed_program_node(const std::shared_ptr<crop> prim, program_impl& prog) : parent(prim, prog) {
        support_padding_all(true);
    }
    program_node& input() const { return get_dependency(0); }
};

using crop_node = typed_program_node<crop>;

template <>
class typed_primitive_inst<crop> : public typed_primitive_inst_base<crop> {
    using parent = typed_primitive_inst_base<crop>;

public:
    static layout calc_output_layout(crop_node const& node);
    static std::string to_string(crop_node const& node);
    typed_primitive_inst(network_impl& network, crop_node const& node);

private:
    void on_execute() override;

    void reuse_input();
};

using crop_inst = typed_primitive_inst<crop>;
}  // namespace cldnn
