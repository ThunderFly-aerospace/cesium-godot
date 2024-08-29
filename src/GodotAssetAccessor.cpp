#include "GodotAssetAccessor.h"

#include "CesiumAsync/IAssetRequest.h"
#include "CesiumAsync/IAssetResponse.h"

#include "godot_cpp/variant/dictionary.hpp"

#include <memory>
#include <utility> 

namespace CesiumGodot
{    
    std::pair<std::string, CesiumAsync::HttpHeaders> parseHeaders(godot::Dictionary gdHeaders)
    {
        CesiumAsync::HttpHeaders csHeaders;

        return {"",  std::move(csHeaders) };
    }

    class GodotAssetResponse : public CesiumAsync::IAssetResponse
    {
    public:

        GodotAssetResponse(godot::Ref<godot::HTTPClient> httpClient)
            : m_httpClient(httpClient), m_statusCode(static_cast<uint16_t>(httpClient->get_response_code()))
        {
            
        }

        virtual uint16_t statusCode() const override { return m_statusCode; }

        virtual std::string contentType() const override { return ""; }

        virtual const CesiumAsync::HttpHeaders& headers() const override { return m_headers; }

        virtual gsl::span<const std::byte> data() const override { return gsl::span<const std::byte>(); }

    private:

        uint16_t m_statusCode = 0;
        std::string m_contentType;
        CesiumAsync::HttpHeaders m_headers;
        godot::Ref<godot::HTTPClient> m_httpClient;
    };

    class GodotAssetRequest : public CesiumAsync::IAssetRequest
    {
    public:

        GodotAssetRequest(const std::string& method, const std::string& url, const CesiumAsync::HttpHeaders& headers)
            : m_method(method), m_url(url), m_headers(headers)
        {
        }

        virtual const std::string& method() const override { return m_method; }

        virtual const std::string& url() const override { return m_url; }

        virtual const CesiumAsync::HttpHeaders& headers() const override { return m_headers; }

        virtual const CesiumAsync::IAssetResponse* response() const override { return m_response.get(); }
    
    private:

        std::string m_method;
        std::string m_url;
        CesiumAsync::HttpHeaders m_headers;
        std::unique_ptr<GodotAssetResponse> m_response;
    };

    GodotAssetAccessor::GodotAssetAccessor()
        : m_userAgent("Mozilla 5.0/ Cesium Godot Plugin")
    {
        m_httpClient.instantiate();
    }

    GodotAssetAccessor::~GodotAssetAccessor()
    {
    }

    CesiumAsync::Future<std::shared_ptr<CesiumAsync::IAssetRequest>> GodotAssetAccessor::get( 
        const CesiumAsync::AsyncSystem &asyncSystem, 
        const std::string &url,
        const std::vector<CesiumAsync::IAssetAccessor::THeader> &headers )
    {
        return asyncSystem.createFuture<std::shared_ptr<CesiumAsync::IAssetRequest>>( [&](const auto& promise) {

        });
    }

    CesiumAsync::Future<std::shared_ptr<CesiumAsync::IAssetRequest>> GodotAssetAccessor::request(
        const CesiumAsync::AsyncSystem &asyncSystem, const std::string &verb,
        const std::string &url, const std::vector<THeader> &headers,
        const gsl::span<const std::byte> &contentPayload )
    {
        return asyncSystem.createFuture<std::shared_ptr<CesiumAsync::IAssetRequest>>( [&](const auto& promise) {

        });
    }
}
