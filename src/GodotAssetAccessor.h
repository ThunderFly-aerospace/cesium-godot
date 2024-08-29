#pragma once

#include "godot_cpp/classes/http_client.hpp"

#include "CesiumAsync/AsyncSystem.h"
#include "CesiumAsync/IAssetAccessor.h"

#include <memory>

namespace CesiumGodot
{

    /// @brief Implementation of CesiumAsync::IAssetAccessor that uses Godot's HTTPClient
    class GodotAssetAccessor : public CesiumAsync::IAssetAccessor
    {
    public:
        GodotAssetAccessor();
        ~GodotAssetAccessor();

        virtual CesiumAsync::Future<std::shared_ptr<CesiumAsync::IAssetRequest>>
            get(const CesiumAsync::AsyncSystem& asyncSystem,
                const std::string& url,
                const std::vector<CesiumAsync::IAssetAccessor::THeader>& headers) override;

        
        virtual CesiumAsync::Future<std::shared_ptr<CesiumAsync::IAssetRequest>> 
            request(const CesiumAsync::AsyncSystem& asyncSystem,
                    const std::string& verb,
                    const std::string& url,
                    const std::vector<CesiumAsync::IAssetAccessor::THeader>& headers,
                    const gsl::span<const std::byte>& contentPayload) override;
        
    private:

        /// @brief Godot HTTPClient resource for making http requests 
        godot::Ref<godot::HTTPClient> m_httpClient;

        godot::String m_userAgent; 
        godot::Dictionary m_gdHeaders;
    };


} // namespace CesiumGodot
