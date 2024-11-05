/*
 * Copyright (c) 2024, Shannon Booth <shannon@serenityos.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <LibJS/Runtime/Realm.h>
#include <LibWeb/Forward.h>
#include <LibWeb/HTML/Scripting/SyntheticRealmSettings.h>

namespace Web::Bindings {

struct SyntheticHostDefined : public JS::Realm::HostDefined {
    SyntheticHostDefined(HTML::SyntheticRealmSettings synthetic_realm_settings)
        : synthetic_realm_settings(move(synthetic_realm_settings))
    {
    }

    virtual ~SyntheticHostDefined() override = default;
    virtual void visit_edges(JS::Cell::Visitor& visitor) override;

    HTML::SyntheticRealmSettings synthetic_realm_settings;
};

}