export function setKey(key: string)
{
    document.cookie = `aes_key=${encodeURIComponent(key)}; path=/; SameSite=Strict`;
}

export function getKey(): string | null
{
    const match = document.cookie.match(
        new RegExp("(^| )aes_key=([^;]+)")
    );

    return match ? decodeURIComponent(match[2]) : null;
}

export function clearKey()
{
    document.cookie = "aes_key=; Max-Age=0; path=/";
}