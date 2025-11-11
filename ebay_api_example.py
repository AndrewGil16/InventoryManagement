"""
ebay_api_example.py
-------------------
Basic example showing how to connect to the eBay API, authenticate, and
retrieve your active listings.

Requirements:
    pip install requests
    pip install python-dotenv   # optional if you want to load credentials from a .env file

References:
    eBay Developer Docs: https://developer.ebay.com/api-docs/static/rest-request-components.html
"""

import requests
import os
from dotenv import load_dotenv

# Load credentials from .env file (recommended for security)
# .env file example:
# EBAY_APP_ID=your-app-id
# EBAY_CERT_ID=your-cert-id
# EBAY_DEV_ID=your-dev-id
# EBAY_AUTH_TOKEN=your-oauth-token
load_dotenv()

# ---- eBay API credentials ----
APP_ID = os.getenv("EBAY_APP_ID")
CERT_ID = os.getenv("EBAY_CERT_ID")
DEV_ID = os.getenv("EBAY_DEV_ID")
AUTH_TOKEN = os.getenv("EBAY_AUTH_TOKEN")

# ---- API Endpoint ----
# This example uses the "Sell Inventory API" (sandbox endpoint for testing)
EBAY_API_URL = "https://api.sandbox.ebay.com/sell/inventory/v1/inventory_item"

# ---- Example function to list all inventory items ----
def get_inventory_items():
    """
    Retrieves all active inventory items from your eBay account.
    Replace the endpoint if you want to use a different API (e.g., Trading, Fulfillment).
    """
    headers = {
        "Authorization": f"Bearer {AUTH_TOKEN}",
        "Content-Type": "application/json",
        "Accept": "application/json",
    }

    response = requests.get(EBAY_API_URL, headers=headers)

    if response.status_code == 200:
        data = response.json()
        print("✅ Inventory Items Retrieved:")
        for item in data.get("inventoryItems", []):
            sku = item.get("sku", "N/A")
            title = item.get("product", {}).get("title", "No Title")
            print(f" - SKU: {sku} | Title: {title}")
    else:
        print(f"❌ Error {response.status_code}: {response.text}")

# ---- Main section ----
if __name__ == "__main__":
    print("Connecting to eBay API...")
    get_inventory_items()
