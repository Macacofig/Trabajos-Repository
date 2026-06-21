import type { Country } from '../types/country';

type Props = {
  country: Country;
  onClick: () => void;
};

export default function CountryCard({ country, onClick }: Props) {
  return (
    <div className="card" onClick={onClick}>
      <img src={country.flags.png} alt="flag" />

      <div className="card-body">
        <h3>{country.name.common}</h3>
        <p><strong>Capital:</strong> {country.capital?.[0]}</p>
        <p><strong>Región:</strong> {country.region}</p>
      </div>
    </div>
  );
}