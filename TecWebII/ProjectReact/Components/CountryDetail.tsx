import type { Country } from '../types/country';

type Props = {
  country: Country;
  onBack: () => void;
};

export default function CountryDetail({ country, onBack }: Props) {
  return (
    <div className="detail">
      <button className="back" onClick={onBack}>
        ← Volver
      </button>

      <div className="detail-card">
        <img src={country.flags.png} alt="flag" />

        <div>
          <h2>{country.name.common}</h2>

          <p><strong>Población:</strong> {country.population}</p>
          <p><strong>Región:</strong> {country.region}</p>
          <p><strong>Capital:</strong> {country.capital?.[0]}</p>

          <p>
            <strong>Idiomas:</strong>{' '}
            {country.languages &&
              Object.values(country.languages).join(', ')}
          </p>

          <p>
            <strong>Moneda:</strong>{' '}
            {country.currencies &&
              Object.values(country.currencies)[0]?.name}
          </p>

          <p><strong>Zona horaria:</strong> {country.timezones?.join(', ')}</p>

          {country.maps?.googleMaps && (
            <a href={country.maps.googleMaps} target="_blank">
              Ver en Google Maps
            </a>
          )}
        </div>
      </div>
    </div>
  );
}