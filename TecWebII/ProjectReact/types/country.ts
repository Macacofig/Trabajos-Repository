export type Country = {
  name: { common: string };
  capital?: string[];
  region: string;
  population: number;
  flags: { png: string };
  languages?: Record<string, string>;
  currencies?: Record<string, { name: string }>;
  timezones?: string[];
  maps?: { googleMaps?: string };
};